#pragma once

#include "List.h"
#include <functional>
#include <iostream>
#include <type_traits>
#include <utility>

template<size_t D, size_t S>
struct P {
    static constexpr size_t dim = D;
    static constexpr size_t stride = S;
};

template<typename L> struct RecalcStrides;

template<          >                                 struct RecalcStrides<EmptyList>          { using type = EmptyList;                     static const size_t carry = 1;};
template<size_t D, size_t S, typename L>            struct RecalcStrides<List<P<D, S >, L>>   { using Tmp = RecalcStrides<L>;  using type = List<P<D, Tmp::carry>, typename Tmp::type>;      static const size_t carry = D*Tmp::carry; };
//template<size_t D1, size_t S1, size_t D2, size_t S2> struct RecalcStrides<List<P<D1, S1>, P<D2, S2>>>{ using type = List<P<D1, D2*S2>, P<D2, S2>>; static const size_t carry = D1*D2*S2; };
//template<size_t D,  size_t S, typename L>            struct RecalcStrides<List<P<D, S>,   L>>        { using Tmp = RecalcStrides<L>; using type = List<P<D, Tmp::carry>, typename Tmp::type>; static const size_t carry = D*Tmp::carry; };

template<typename L> using recalcstrides_t = typename RecalcStrides<L>::type;

template<typename L> struct Size;
template<                               >            struct Size<EmptyList>{ static constexpr size_t size = 1; };
//template<size_t D,  size_t S            >            struct Size<List<P<D, S>,   EmptyList>>{ static constexpr size_t size = D; };
template<size_t D,  size_t S, typename L>            struct Size<List<P<D, S>,   L        >>{ static constexpr size_t size = Size<L>::size * D; };
//template<size_t D1, size_t S1, size_t D2, size_t S2> struct Size<List<P<D1, S1>, P<D2, S2>>>{ static constexpr size_t size = D1*D2; };

template<typename L> static constexpr size_t Size_t = Size<L>::size;

template<int N, typename S> struct DropFront;

template<>                               struct DropFront<0, EmptyList       >{ using type = EmptyList; };
template<int N,  typename H, typename T> struct DropFront<N, List<H,       T>>{ using type = typename DropFront<N - 1, T>::type; };
template<size_t D, size_t S, typename T> struct DropFront<0, List<P<D, S>, T>>{ using type = List<P<D, S>, T>; };

template<int N, typename S> using dropfront_t = typename DropFront<N, S>::type;

template<int D, size_t L, typename S> struct Subdiv;

template<int D, size_t L, typename H, typename T>
struct Subdiv<D, L, List<H, T>> {
    using type = List<H, typename Subdiv<D - 1, L, T>::type>;
};

template<size_t L, size_t D, size_t S, typename T>
struct Subdiv<0, L, List<P<D, S>, T>> {
    using type = List<P<L, D / L*S>, List<P<D / L, S>, T>>;
};

template<int D, size_t L, typename S>
using subdiv_t = typename Subdiv<D, L, S>::type;

template<int D, typename S> struct Flip;

template<int D, typename H, typename T>
struct Flip<D, List<H, T>> {
    using type = List<H, typename Flip<D - 1, T>::type>;
};

template<typename A, typename B, typename T>
struct Flip<0, List<A, List<B, T>>> {
    using type = List<B, List<A, T>>;
};

template<int D, typename S>
using flip_t = typename Flip<D, S>::type;

template<typename Ptr, typename T, typename Ds> class View;

template<int d, typename Ptr, typename T, typename Ds>
auto flip(View<Ptr, T, Ds> v) {
    return View<Ptr, T, flip_t<d, Ds>>(v.data);
}

template<int d, size_t l, typename Ptr, typename T, typename Ds>
auto subdiv(View<Ptr, T, Ds> v) {
    return View<Ptr, T, subdiv_t<d, l, Ds>>(v.data);
}

template<int d, typename Ptr, typename T, typename Ds>
auto dropfront(View<Ptr, T, Ds> v) {
    return View<Ptr, T, dropfront_t<d, Ds>>(v.data);
}

template<int d, typename Ptr, typename T, typename Ds>
auto keepback( View<Ptr, T, Ds> v ){ return View<Ptr, T, dropfront_t<Length<Ds>::length-d, Ds>>(v.data); }

template<typename Ptr, typename T, typename Ds>
auto recalcstrides(View<Ptr, T, Ds> v) {
	return View<Ptr, T, recalcstrides_t<Ds>>(v.data);
}

template<int d, typename Ptr, typename T, typename Ds>
auto AllocateViewSimilarToButDropFrontDimensionsUpTo(View<Ptr, T, Ds> v)
{
	using DResult = recalcstrides_t<dropfront_t<Length<Ds>::length-d, Ds>>;
	return View<Ptr, T, DResult>(new T[ Size<DResult>::size ]);
}

template<typename... Ps>
void Deallocate( View<Ps...> v ){ delete[] v.data; }

template<typename Ptr, typename T, typename D, typename Ds>
class View<Ptr, T, List<D, Ds>> {
public:
    View(Ptr data) : data(data) {}
    static constexpr size_t size = D::dim;

    View<Ptr, T, List<D, Ds>>& operator=(const View<Ptr, T, List<D, Ds>>& other) const {
        for (size_t i = 0; i < D::dim; ++i) {
            (*this)[i] = other[i];
        }
        return *this;
    }

    auto operator[](size_t idx) const {
        return View<Ptr, T, Ds>(data + idx*D::stride);
    }

    //template<typename I, typename... Idx>
    //auto operator()(I i, Idx... idx) const {
    //    return slice<EmptyList, List<D, Ds>>(0, i, idx...);
    //}

    Ptr data;
private:
    //template<typename SortedDims, typename Dims, typename I, typename... Idx, std::enable_if_t<std::is_placeholder_v<I> != 0, int> = 0>
    //auto slice(size_t offset, I i, Idx... idx) const {
    //    return slice<typename Insert<SortedDims, KeyValuePair<Int<std::is_placeholder_v<I>>, typename Dims::head>>::type, typename Dims::tail>(offset, idx...);
    //}

    //template<typename SortedDims, typename Dims, typename I, typename... Idx, std::enable_if_t<std::is_placeholder_v<I> == 0, int> = 0>
    //auto slice(size_t offset, I i, Idx... idx) const {
    //    return slice<SortedDims, typename Dims::tail>(offset + i * Dims::head::stride, idx...);
    //}

    //template<typename SortedDims, typename Dims>
    //auto slice(size_t offset) const {
    //    return View<Ptr, T, typename Concat<typename Map<SortedDims, get_value>::type, Dims>::type>(data + offset);
    //}
};

template<typename Ptr, typename T, typename Dims>
std::ostream& operator<<(std::ostream& out, const View<Ptr, T, Dims>& v) {
    out << "{";
    for (size_t i = 0; i < Dims::head::dim; ++i) {
        out << (i ? "," : "") << v[i];
    }
    return out << "}";
}

template<typename Ptr, typename T>
class View<Ptr, T, EmptyList> {
public:
    View(Ptr data) : data(data) {}

    auto& operator=(const View<Ptr, T, EmptyList>& other) const {
        *data = *other.data;
        return *this;
    }

    void operator=(T x) const {
        *data = x;
    }

    operator T() const {
        return *data;
    }

    Ptr data;
};

template<typename Ptr, typename T>
std::ostream& operator<<(std::ostream& out, const View<Ptr, T, EmptyList>& v) {
    return out << (T)v;
}
