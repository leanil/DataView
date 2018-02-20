#include <iostream>
#include <tuple>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <fstream>

#define fw(X, x) std::forward<X>(x)
#define lfw(x) std::forward<decltype(x)>(x)

//Identity function:
auto id = [](auto&& x){ return std::forward<decltype(x)>(x); };

//Left identity:
auto leftid = [](auto&& x, auto&& y){ return std::forward<decltype(x)>(x); };

//Constant function:
template<typename T>
auto constant(T&& t){ return [t=std::forward<T>(t)](auto&&){ return t; }; };

//C++ helper for storing a forwarded type
template<typename T> using Bare = std::remove_const_t<std::remove_reference_t<T>>;

//SFINAE helper (will be obsolete in C++17)
template<typename T> struct Void{ typedef void type; };

template<typename T> struct Ty : T{ operator T() const { return T{}; } };

template<typename T> struct Decay       { using Res = T; };
template<typename T> struct Decay<Ty<T>>{ using Res = T; };

template<bool b> struct Bool{ static const int value = b; operator bool() const { return b; } };

using True  = Bool<true>;
using False = Bool<false>;

//Check constraints (concepts)
template<typename T, template<typename> class F, typename R = void> struct Is                                   { using Res = False; };
template<typename T, template<typename> class F>                    struct Is<T, F, typename Void< F<T> >::type>{ using Res = True;  };

template<typename T> struct Not;
template<bool b> struct Not<Bool<b>>{ using Res = Bool<(!b)>; };

template<bool i, bool j> auto operator && (Bool<i> const&, Bool<j> const&){ return Bool<(i&&j)>(); }
template<bool i, bool j> auto operator || (Bool<i> const&, Bool<j> const&){ return Bool<(i||j)>(); }

auto And = [](auto const& x, auto const& y){ return x && y; };
auto Or  = [](auto const& x, auto const& y){ return x || y; };

auto& operator<< (std::ostream& os, True  ){ os << "True"; return os; }
auto& operator<< (std::ostream& os, False ){ os << "False"; return os; }

template<typename T, typename U> auto is_same_type(T const&, U const&){ return Bool< std::is_same<typename Decay<T>::Res, typename Decay<U>::Res>::value >(); }

template<typename FT, typename FF> auto select(True&&,  FT&& ft, FF&& ff){ return ft; }
template<typename FT, typename FF> auto select(False&&, FT&& ft, FF&& ff){ return ff; }
template<typename T>               auto select(bool b,  T&&  t, T&&   f){ return b ? t : f; }

template<int i> struct Int{ static const int value = i; operator int() const { return i; } };

template<int i, int j> auto operator+ (Int<i> const&, Int<j> const&){ return Int<(i+j)>(); }
template<int i, int j> auto operator- (Int<i> const&, Int<j> const&){ return Int<(i-j)>(); }
template<int i, int j> auto operator* (Int<i> const&, Int<j> const&){ return Int<(i*j)>(); }
template<int i, int j> auto operator< (Int<i> const&, Int<j> const&){ return Bool<(i< j)>(); }
template<int i, int j> auto operator<=(Int<i> const&, Int<j> const&){ return Bool<(i<=j)>(); }
template<int i, int j> auto operator==(Int<i> const&, Int<j> const&){ return Bool<(i==j)>(); }
template<int i, int j> auto operator!=(Int<i> const&, Int<j> const&){ return Bool<(i!=j)>(); }
template<int i, int j> auto operator>=(Int<i> const&, Int<j> const&){ return Bool<(i>=j)>(); }
template<int i, int j> auto operator> (Int<i> const&, Int<j> const&){ return Bool<(i> j)>(); }

auto Add = [](auto const& x, auto const& y){ return x + y; };
auto Mul = [](auto const& x, auto const& y){ return x * y; };

//C++ compile time helpers:
template<typename... Ts>   using Size = Int<sizeof...(Ts)>;
template<typename... Ints> struct Integers{ template<typename N> auto operator[](N const& n){ return n; } };
template<typename... Ints> auto size( Integers<Ints...> const& ){ return Size<Ints...>(); }

template<typename T> auto size( Ty<T> const& ){ return size(T()); }

//Integer sequence generation helpers:
namespace detail
{
    template<typename Ns> struct MakeIntSeqImpl;
    template<int... ints> struct MakeIntSeqImpl< std::integer_sequence<int, ints...> >{ using Ret = Integers<Int<ints>...>; };
}

//Index sequence:
template<typename    N > using Seq = typename detail::MakeIntSeqImpl< std::make_integer_sequence<int, N::value> >::Ret;
template<typename... Ts> using SeqTo = Seq<Size<Ts...>>;
template<typename N> auto seqto(N const& n){ return Seq<N>{}; }

template<int i>
auto& operator<< (std::ostream& os, Int<i> ){ os << "Int<" << i << ">"; return os; }

//Compile time indexible type list:
template<typename T, int N>struct TyListElem{ using type = T; };
template<int i, typename T> static TyListElem<T, i> TyListSelect(TyListElem<T, i>);

template<typename Ns, typename... Ts> struct TyListBase;
template<int... Ns,   typename... Ts> struct TyListBase<Integers<Int<Ns>...>, Ts...> : TyListElem<Ts, Ns>...{};

template <int i, typename ...Ts>
struct TyListIdx
{
	using Q = decltype(TyListSelect<i>(TyListBase<SeqTo<Ts...>, Ts...>{}));
    using Res = typename Q::type;
};

template<typename... Ts> struct TyList
{
    template<typename N> using Idx = typename TyListIdx<N::value, Ts...>::Res;

	template<typename N> auto operator[](N const& n) const { return Idx<N>(); }
};

template<typename... Ts>
auto tylist(Ts const&... ts){ return TyList<Ts...>{}; }

template<typename... Ts>
auto recons( TyList<Ts...> const& ){ return [](auto const&... as){ return tylist(as...); }; }

template<typename... Ts>
Int<sizeof...(Ts)> size( TyList<Ts...> const& ){ return Int<sizeof...(Ts)>{}; }

template<typename T, int n>
struct TupleElem
{
	using type = T;
	T value;
};

struct Constructor{};

template<typename Ns, typename... Ts> struct TupleImpl;
template<> struct TupleImpl<Integers<>>{ TupleImpl(Constructor&&){} };
template<int... Ns,   typename... Ts> struct TupleImpl<Integers<Int<Ns>...>, Ts...> : TupleElem<Ts, Ns>...
{
	template<typename... As> TupleImpl(Constructor&&, As&&... as):TupleElem<Ts, Ns>{ fw(As, as) }...{}
};

template<typename... Ts> struct Tuple : TupleImpl<SeqTo<Ts...>, Ts...>
{
	template<typename... As> Tuple(Constructor&&, As&&... as):TupleImpl<SeqTo<Ts...>, Ts...>{Constructor(), fw(As, as)...}{}

	using L = TyList<Ts...>;
	template<typename N> auto& operator[](N const& n)
    { 
        using T = typename L::template Idx<N>;
        return (*(TupleElem<T, N::value>*)this).value;
	}

	template<typename N> auto& operator[](N const& n) const
    { 
        using T = typename L::template Idx<N>;
        return (*(TupleElem<T, N::value>*)this).value;
	}
};

template<typename... Ts>
auto tup(Ts&&... ts){ return Tuple<Bare<Ts>...>{ Constructor(), fw(Ts, ts)... }; }

template<typename... Ts>
auto recons( Tuple<Ts...> const& ){ return [](auto&&... as){ return tup(lfw(as)...); }; }

template<typename... Ts>
Int<sizeof...(Ts)> size( Tuple<Ts...> const& ){ return Int<sizeof...(Ts)>{}; }


template<typename... Ns, typename F, typename I>
auto map_impl(Integers<Ns...>&&, F&& f, I&& i){ return recons(i)( f(i[Ns()])... ); }

template<typename F, typename I>
auto map(F&& f, I&& i){ return map_impl(seqto(size(i)), fw(F, f), fw(I, i)); }

template<typename N, typename F, typename... Is>
auto zip_impl_elem(N n, F const& f, Is&&... is){ return f(is[n]...); }

template<typename... Ns, typename F, typename I, typename... Is>
auto zip_impl(Integers<Ns...>&&, F&& f, I&& i, Is&&... is){ return recons(i)( zip_impl_elem(Ns(), f, i, is...)... ); }

template<typename F, typename I, typename... Is>
auto zip(F&& f, I&& i, Is&&... is){ return zip_impl(seqto(size(i)), fw(F, f), fw(I, i), fw(Is, is)...); }

template<int idx, typename F, typename Acc, typename I>
auto foldl_impl(Int<idx>, Int<idx> Idx, F const& f, Acc&& acc, I const& i){ return f(fw(Acc, acc), i[Idx]); }

template<int il, int idx, typename F, typename Acc, typename I>
auto foldl_impl(Int<il> IL, Int<idx> Idx, F const& f, Acc&& acc, I const& i){ return foldl_impl(IL, Int<idx+1>(), f, f(fw(Acc, acc), i[Idx]), i); }

template<typename F, typename Z, typename I>
auto foldl(F&& f, Z&& z, I&& i){ return foldl_impl(size(i)-Int<1>(), Int<0>(), fw(F, f), fw(Z, z), fw(I, i)); }

template<int idx, typename F, typename M, typename Acc, typename... Is>
auto rnz_impl(Int<-1>, Int<idx> Idx, F const& f, M const& m, Acc&& acc, Is const&... is){ return acc; }

template<int idx, typename F, typename M, typename Acc, typename... Is>
auto rnz_impl(Int<idx>, Int<idx> Idx, F const& f, M const& m, Acc&& acc, Is const&... is){ return f(fw(Acc, acc), m(is[Idx]...)); }

template<int il, int idx, typename F, typename M, typename Acc, typename... Is>
auto rnz_impl(Int<il> IL, Int<idx> Idx, F const& f, M const& m, Acc&& acc, Is const&... is){ return rnz_impl(IL, Int<idx+1>(), f, m, f(fw(Acc, acc), m(is[Idx]...)), is...); }

template<typename F, typename M, typename Z, typename I, typename... Is>
auto rnz(F&& f, M&& m, Z&& z, I&& i, Is&&... is){ return rnz_impl(size(i)-Int<1>(), Int<0>(), fw(F, f), fw(M, m), fw(Z, z), fw(I, i), fw(Is, is)...); }


template<int idx, typename P, typename D, typename I>
auto findfst_impl(Int<idx>, Int<idx> Idx, P const& p, D&& d, I const& i){ return select(p(i[Idx]), Idx, d); }

template<int il, int idx, typename P, typename D, typename I>
auto findfst_impl(Int<il> IL, Int<idx> Idx, P const& p, D&& d, I const& i){ return select(p(i[Idx]), Idx, findfst_impl(IL, Int<idx+1>(), p, fw(D, d), i)); }

template<typename P, typename D, typename I>
auto findfst(P&& p, D&& d, I&& i){ return findfst_impl(size(i)-Int<1>(), Int<0>(), fw(P, p), fw(D, d), fw(I, i)); }

template<typename X, typename D, typename I>
auto index_of_type(X&& x, D&& d, I&& i){ return findfst( [&](auto const& y){ return is_same_type(x, y); }, fw(D, d), fw(I, i) ); }

//Handy specialzations:
template<typename I> auto sum    (I&& i){ return foldl(Add, Int<0>(), fw(I, i)); }
template<typename I> auto product(I&& i){ return foldl(Mul, Int<1>(), fw(I, i)); }
template<typename I> auto or_all (I&& i){ return foldl(Or , False() , fw(I, i)); }
template<typename I> auto and_all(I&& i){ return foldl(And, True()  , fw(I, i)); }

//Expand indexible to variadic function call:
namespace detail
{
	template<typename F, typename Indexible, typename... Is>
	auto expand_impl(F&& f, Integers<Is...> const&, Indexible&& i){ return f( i[Is()]... ); }
}

template<typename NArgs, typename F, typename Indexible>
auto expand(F&& f, Indexible&& args)
{
	return detail::expand_impl(fw(F, f), Seq<NArgs>(), std::forward<Indexible>(args));
}



//------------------------------------------------------------------------

//Maybe, a value or nothing:
struct Nothing{};
struct Just{};
template<typename T> struct Maybe
{
	T value;
	bool exists;

	Maybe():value(), exists(false){}
	Maybe( Just, T&& val ):value{std::forward<T>(val)}, exists{true}{}
	Maybe( Nothing       ):value{}, exists{false}{}
	Maybe( Maybe const& cpy ):value(cpy.value), exists(cpy.exists){}
	Maybe( Maybe && cpy ):value(std::move(cpy.value)), exists(cpy.exists){ }
	Maybe& operator=( Maybe const& m ){ if(&m != this){ value = m.value; exists = m.exists; } return *this; }
	operator bool() const { return exists; }
};

//Helper for construction:
template<typename T>
Maybe<T> just(T&& t){ return Maybe<Bare<T>>( Just(), std::forward<T>(t) ); }

//Fancy output for debugging:
template<typename A>
auto& operator<<(std::ostream& os, Maybe<A> const& m)
{
	if(m){ os << m.value; }
	else { os << "Nothing"; }
	return os;
}

//Either, choice between two values
template<typename L, typename R> struct Either
{
	union Choice
	{
		L left;
		R right;

		Choice(){}
		Choice(L const& l):left{l}{}
		Choice(R const& r):right{r}{}
		~Choice(){}
	} choice;
	bool isl;

	Either(Either const& cpy):isl(cpy.isl)
	{
		if( isl ){ new (&choice.left)  auto(cpy.choice.left); }
		else     { new (&choice.right) auto(cpy.choice.right); }
	}

	Either(L const& l):choice(l), isl(true ){}
	Either(R const& r):choice(r), isl(false){}

	~Either()
	{
		if( isl ){ choice.left.~L(); }
		else     { choice.right.~R(); }
	}

	bool is_left () const { return  isl; }
	bool is_right() const { return !isl; }
};

template<typename L, typename R> auto fromLeft ( L const& left,  Either<L, R> const& e){ return e.is_left () ? e.choice.left  : left;  }
template<typename L, typename R> auto fromRight( R const& right, Either<L, R> const& e){ return e.is_right() ? e.choice.right : right; }

template<typename L, typename R> auto either(L const& left ){ return Either<L, R>(left); }
template<typename L, typename R> auto either(R const& right){ return Either<L, R>(right); }

//fmap for Either, Haskell convention: only transforms second arg:
template<typename F, typename A, typename B = std::result_of_t<F(A)>>
Either<A, B> map(F&& f, Either<A, A> const& e)
{
	if(e.isl()){ return either<A, B>(e.choice.left); }
	else       { return either<A, B>(f(e.choice.right)); }
}

template<typename F, typename A, typename B = std::result_of_t<F(A)>>
Either<A, B> map(F&& f, Either<A, A>&& e)
{
	if(e.isl()){ return either<A, B>(e.choice.left); }
	else       { return either<A, B>(f(e.choice.right)); }
}

//Fancy output for debugging:
template<typename A, typename B>
auto& operator<<(std::ostream& os, Either<A, B> const& e)
{
	if(e.is_left()){ os << e.choice.left; }
	else           { os << e.choice.right; }
	return os;
}

//Utilities from Control.Arrow:

//Fan in: f:a->c, g:b->c, returns h: Either a, b -> c
template<typename A, typename B, typename F, typename G>
auto fanIn(F&& f, G&& g)
{
	return [ff=std::forward<F>(f), gg=std::forward<G>(g)]( Either<A, B> const& e )
	{
		if(e.is_left()){ return ff(e.choice.left); }
		else           { return gg(e.choice.right); }
	};
}

//Fan out: f:a->b, g:a->c, returns h: a -> (b, c)
template<typename F, typename G>
auto fanOut(F&& f, G&& g)
{
	return [ff=std::forward<F>(f), gg=std::forward<G>(g)]( auto&& x )
	{
		return std::make_pair( ff(x), gg(x) );
	};
}

//Split (product): f:a->c, g:b->d, returns h: (a, b)->(c, d)
template<typename F, typename G>
auto splitProd(F&& f, G&& g)
{
	return [ff=std::forward<F>(f), gg=std::forward<G>(g)]( auto&& p )
	{
		return std::make_pair(ff(p.first), gg(p.second));
	};
}

//Split (sum): f:a->c, g:b->d, returns h: Either a b -> Either c d
template<typename A, typename B, typename F, typename G>
auto splitSum(F&& f, G&& g)
{
	using C = std::result_of_t<F(A)>;
	using D = std::result_of_t<G(B)>;
	return [ff=std::forward<F>(f), gg=std::forward<G>(g)]( Either<A, B> const& e )
	{
		return e.is_left() ? either<C, D>( ff(e.choice.left) ) : either<C, D>( gg(e.choice.right) );
	};
}

//fmap on std::vectors without iterators:
template<typename F, typename T>
auto map(F&& f, std::vector<T> const& v)
{
	using B = std::result_of_t<F(T)>;
	std::vector<B> res(v.size());
	for(int i=0; i<(int)res.size(); ++i){ res[i] = f(v[i]); }
	return res;
}

//fmap on std::vectors without iterators:
template<typename F, typename T>
auto map(F&& f, std::vector<T>&& v)
{
	using B = std::result_of_t<F(T)>;
	std::vector<B> res(v.size());
	for(int i=0; i<(int)res.size(); ++i){ res[i] = f(v[i]); }
	return res;
}

//Fix point combinator:
/*template<template<typename> class F> struct Fix : F<Fix<F>>
{
	Fix() {}
	explicit Fix(const F<Fix<F>>& f) : F<Fix<F>>(f) {}
};

template<template<typename> class F> auto unfix( Fix<F> const& x ){ return F<Fix<F>>{x}; }
template<template<typename> class F> auto unfix( Fix<F> &&     x ){ return F<Fix<F>>{x}; }

template<template<typename> class F> auto fix( F<Fix<F>> const& x ){ return Fix<F>{x}; }
template<template<typename> class F> auto fix( F<Fix<F>> &&     x ){ return Fix<F>{x}; }*/

//Fix point combinator with an additional pass through parameter:
template<template<typename...> class F, typename... A> struct Fix : F<Fix<F, A...>, A...>
{
	Fix() {}
	explicit Fix(const F<Fix<F, A...>, A...>& f) : F<Fix<F, A...>, A...>(f) {}
};

template<template<typename...> class F, typename... A> auto unfix( Fix<F, A...> const& x ){ return F<Fix<F, A...>, A...>{x}; }
template<template<typename...> class F, typename... A> auto unfix( Fix<F, A...> &&     x ){ return F<Fix<F, A...>, A...>{x}; }

template<template<typename...> class F, typename... A> auto fix( F<Fix<F, A...>, A...> const& x ){ return Fix<F, A...>{x}; }
template<template<typename...> class F, typename... A> auto fix( F<Fix<F, A...>, A...> &&     x ){ return Fix<F, A...>{x}; }

//Algebras, Coalgebras and Structured Recursion Schemes
//Based on Category Extras: https://hackage.haskell.org/package/category-extras-1.0.2
//See also: http://comonad.com/reader/2009/recursion-schemes/
//See also: http://ericniebler.com/2013/07/16/f-algebras-and-c/

//Algebra: f a -> a
template<typename C, typename Impl> struct Alg
{
	Impl impl;
	using CarrierType = C;
	template<typename FA> auto operator()(FA&& fa) const { return impl(std::forward<FA>(fa)); }
};

template<typename Carrier, typename    F > auto alg       (F       f ){ return Alg<Carrier, F>{ f }; }
template<typename Carrier, typename... Fs> auto alg_helper(Fs&&... fs){ return alg<Carrier>( [=](auto const& x){ return match(x, fs...); } ); }

//Coalgebra: a -> f a
template<typename Impl, template<typename, typename...> class F, typename... Params> struct CoAlg
{
	Impl impl;
	template<typename A> using Structure = F<A, Params...>;
	template<typename A> auto operator()(A&& a) const { return impl(std::forward<A>(a)); }
};

template<template<typename, typename...> class F, typename... Params, typename G> auto coalg(G&& g){ return CoAlg<G, F, Params...>{ g }; }

//Catamorphism: bottom-up traversal / consumption
//Functor f => (f a -> a) -> Fix f -> a
template<typename A, typename Impl, typename FTree>
A cata(Alg<A, Impl> const& alg, FTree&& tree)
{
	auto f = [&](auto&& tree2){ return cata(alg, std::forward<decltype(tree2)>(tree2)); };
	return alg( map(f, unfix(std::forward<FTree>(tree))) );
}

//Anamorphism: top-down traversal / contruction
//Functor f => (a -> f a) -> a -> Fix f
template<template<typename, typename...> class F, typename... Params, typename Impl, typename A, typename FTree = Fix<F, Params...>>
FTree ana(CoAlg<Impl, F, Params...> const& coalg, A&& seed)
{
	auto f = [&](auto&& ast){ return ana(coalg, std::forward<decltype(ast)>(ast)); };
	return fix( map(f, coalg(std::forward<A>(seed))) );
}

//Paramorphism: bottom-up traversal / consumption giving access to the original structure besides the transformed results
//Functor f => ( (Fix f, f a) -> a) -> Fix f -> a
template<typename A, typename Impl, typename FTree>
A para(Alg<A, Impl> const& alg, FTree&& tree)
{
	auto f = [&](auto&& tree2){ return std::make_pair(tree2, para(alg, tree2)); };
	return alg( map(f, unfix(std::forward<FTree>(tree))) );
}

//Apo RCoalgebra switch: a -> f (Fix f | a)
template<template<typename, typename> class F, typename Br, typename Impl> struct ApoCoAlgSwitch
{
	Impl impl;
	//template<typename A> using Structure = F<A, Br>;
	template<typename A> auto operator()(A&& a) const
	{
		return impl(std::forward<A>(a));
	}
};

template<template<typename, typename> class F, typename Br, typename G> auto apoCoalgSwitch(G g){ return ApoCoAlgSwitch<F, Br, G>{ g }; }

//Apomorphism: top-down traversal / construction, may terminate with full subtree instead of a new seed at each level
//Functor f => ( a -> f (Fix f | a) ) -> a -> Fix f
template<template<typename, typename> class F, typename Br, typename A, typename Impl, typename FTree = Fix<F, Br>>
FTree apo(ApoCoAlgSwitch<F, Br, Impl> const& coalg, A&& seed)
{
	auto f = [&](auto&& tree2){ return fanIn<FTree, Bare<A>>(id, [&](auto&& seed2){ return apo(coalg, lfw(seed2)); })( lfw(tree2) ); };
	return fix( map(f, coalg(std::forward<A>(seed))) );
}

//Hylomorphism: composition of an anamorphism and a catamorphism (operating in this order)
//Functor f => (f a -> a) -> (b -> f b) -> b -> a
template<typename A, typename Impl, template<typename, typename...> class F, typename... Params, typename Impl2, typename B>
A hylo(Alg<A, Impl> const& alg, CoAlg<Impl2, F, Params...> const& coalg, B&& b)
{
	auto f = [&](auto&& tree){ return hylo(alg, coalg, std::forward<decltype(tree)>(tree)); };
	return alg( map(f, coalg(std::forward<B>(b))) );
}

//Elgot Coalgebra switch: b -> Either a (f b)
template<template<typename...> class F, typename Br, typename Ann, typename Impl> struct ElgotCoAlgSwitch
{
	Impl impl;
	template<typename A> using Structure = F<A, Br, Ann>;
	template<typename A> auto operator()(A&& a) const
	{
		return impl(std::forward<A>(a));
	}
};

template<template<typename...> class F, typename Br, typename Ann, typename G> auto elgotCoalgSwitch(G g){ return ElgotCoAlgSwitch<F, Br, Ann, G>{ g }; }

//Elgot-algebra: a hylomorphism that can exit early
//Functor f => (f a -> a) -> (b -> Either a (f b)) -> b -> a
template<typename A, typename Impl, template<typename...> class F, typename Br, typename Ann, typename Impl2, typename B>
A elgot(Alg<A, Impl> const& alg, ElgotCoAlgSwitch<F, Br, Ann, Impl2> const& ecoalg, B const& b)
{
	auto f = [&](auto&& tree){ return elgot(alg, ecoalg, std::forward<decltype(tree)>(tree)); };
	auto c = ecoalg(b);
	return fanIn<A, F<B, Br, Ann>>(id, [&](auto&& tree){ return alg( map(f, std::forward<decltype(tree)>(tree)) ); } )( c );
}

//Runtime branch identifier in the two level branch hierarcy:
struct BranchId
{
	uint64_t id;
	uint32_t list_id() const { return id >> 32; }
	uint32_t item_id() const { return (uint32_t)id; }
	BranchId():id{0}{}
	BranchId(uint32_t const& hi, uint32_t const& lo):id{ (((uint64_t) hi) << 32) | ((uint64_t) lo) }{}
};

bool operator==( BranchId const& b1, BranchId const& b2 ){ return b1.id == b2.id; }

//Base class for user defined branchlists:
template<typename L> struct BranchBase
{
	using List = L;
	template<typename B>
	auto lookup( B const& b ) const
	{
		return findfst( [&](auto x){ return is_same_type(x, b); }, Int<-1>(), L() );
	}

	template<typename Case>
	static std::string as_string( Case const& c ){ return (std::string)c; }

	template<typename N>
	auto operator[](N) const { return L()[N()]; }
};

template<typename L>
auto size( BranchBase<L> const& ){ return size(L()); }

template<typename T, typename I> struct TaggedIndex
{
	using Tag = T;
	using Idx = I;
};

//Two level sumtype case holder, branches are inherited from BranchBase:
template<typename... Branches>
struct BranchList
{
	using List   = TyList<Branches...>;

	template<typename B>
	auto lookup_item( B const& b ) const
	{
		auto is = map( [=](auto l){ return index_of_type(b, Int<-1>(), l); }, tylist(Branches()...) );
		auto ilist = findfst( [](auto x){ return x > Int<-1>(); }, Int<-1>(), is);
		static_assert( decltype(ilist)::value >= 0, "List does not exist in branch lists");
		return TaggedIndex<B, decltype(is[ ilist ]) >{};
	}

	//Workaround clang bug...
	template<typename B>
	bool is_same_item( B const& b, uint32_t const& item_id ) const { return LookUpItemIndex<B>::value == item_id; }

	auto lookup( BranchId const& b ) const { return b; }

	template<typename B>
	auto lookup( B const& b ) const
	{
		auto is = map( [=](auto l){ return index_of_type(b, Int<-1>(), l); }, tylist(Branches()...) );
		auto ilist = findfst( [](auto x){ return x > Int<-1>(); }, Int<-1>(), is);
		static_assert( decltype(ilist)::value >= 0, "List does not exist in branch lists");
		auto iitem = is[ ilist ];
		static_assert( decltype(iitem)::value >= 0, "Item does not exist in selected branch list");
		return BranchId(ilist, iitem);
	}
};

//Sumtype after distributing products over sums, BrList is a BranchList:
template<typename T, typename BrList, typename Annotations>
struct TreeNode
{
	using Branches = BrList;
	BranchId branch;
	Annotations ann;
	std::vector<T> chs;

	BrList branch_list() const { return BrList(); }

	template<typename B>
	bool is_branch(B const& b) const { return BrList().lookup(b) == branch; }

	TreeNode(){}
	TreeNode( TreeNode const& cpy ):branch{cpy.branch}, ann{cpy.ann},           chs{cpy.chs}{}
	TreeNode( TreeNode &&     mv  ):branch{mv.branch},  ann{std::move(mv.ann)}, chs{std::move(mv.chs)}{}
	
	template<typename Br>                               TreeNode( Br const& branch_, Annotations const& ann_)                           :branch{BrList().lookup(branch_)}, ann{ann_}, chs{}{}
	template<typename Br>                               TreeNode( Br const& branch_, Annotations const& ann_, std::vector<T>const& chs_):branch{BrList().lookup(branch_)}, ann{ann_}, chs{ chs_ }{}
	template<typename Br, typename Ch, typename... Chs> TreeNode( Br const& branch_, Annotations const& ann_, Ch&& ch, Chs&&... chs_)   :branch{BrList().lookup(branch_)}, ann{ann_}, chs{ std::vector<T>{ std::forward<Ch>(ch), std::forward<Chs>(chs_)...} }{}

	TreeNode& operator=( TreeNode const& ast ){ if(&ast != this){ branch = ast.branch; ann = ast.ann;            chs = ast.chs;            } return *this; }
	TreeNode& operator=( TreeNode&&      ast ){ if(&ast != this){ branch = ast.branch; ann = std::move(ast.ann); chs = std::move(ast.chs); } return *this; }

	auto&       operator[]( int const& i )       { return chs[i]; }
	auto const& operator[]( int const& i ) const { return chs[i]; }

	int size() const { return (int)chs.size(); }
};

//Helper to build a Tree:
template<typename BrList, typename Elem, typename Ann, typename... Chs>
auto build_node( BrList const& brl, Elem const& elem, Ann const& ann, Chs&&... chs )
{
	return fix( TreeNode<Fix<TreeNode, BrList, Ann>, BrList, Ann>{elem, ann, std::forward<Chs>(chs)...} );
}

//Additional helpers for construction:
template<typename BranchList, typename Elem, typename Ann>
auto from_str(){ return [](auto&& ann){ return build_node( BranchList(), Elem(), Ann{std::forward<decltype(ann)>(ann)} ); }; }

template<typename BranchList, typename Elem, typename Ann>
auto from_chs(){ return [](auto&&... chs){ return build_node( BranchList(), Elem(), Ann{}, std::forward<decltype(chs)>(chs)... ); }; }

template<typename BranchList, typename Ann>
auto from_childsof(){ return [](auto&& node){ return build_node( BranchList(), node.tag, Ann{}, std::forward<decltype(node)>(node).tree.chs ); }; }

//fmap on TreeNode:
template<typename F, typename T, typename Brs, typename Ann, typename U = std::result_of_t<F(T)>> auto map( F&& f, TreeNode<T, Brs, Ann> const& a ){ return TreeNode<U, Brs, Ann>(a.branch, a.ann, map(f, a.chs)); }
template<typename F, typename T, typename Brs, typename Ann, typename U = std::result_of_t<F(T)>> auto map( F&& f, TreeNode<T, Brs, Ann> &&     a ){ return TreeNode<U, Brs, Ann>(a.branch, a.ann, map(f, std::move(a.chs))); }

//equivalences:
template<typename T, typename BrList, typename Ann, typename E>
bool is_same_branch(TreeNode<T, BrList, Ann> const& tree, E const& e){ return tree.branch == BrList().lookup(e); }

template<typename T1, typename BrList1, typename Ann1, typename T2, typename BrList2, typename Ann2, typename E>
bool is_same_branch(TreeNode<T1, BrList1, Ann1> const& tree1, TreeNode<T2, BrList2, Ann2> const& tree2, E const& e){ return tree1.branch == BrList1().lookup(e) && tree2.branch == BrList2().lookup(e); }

//2 level matcher
namespace detail
{
	//struct MatchEnd{ using End = True; };

	//Second level: match a selector against the target branch:
	template<typename Tree, typename F>
	auto match_level2(Tree const& tree, uint32_t const& item_id, F const& f)
	{
		//Debug:
		//if( !f.is_in(typename Tree::Branches(), item_id) ){ std::cout << "Totality check fail!\n"; }
		//return f(tree);
		//return f.template apply_end<typename Tree::Branches>(item_id, tree);
		return f.apply_end(item_id, tree);
	}

	template<typename Tree, typename F, typename F2, typename... Fs>
	auto match_level2(Tree const& tree, uint32_t const& item_id, F const& f, F2 const& f2, Fs const&... fs)
	{
		//return f.template apply<typename Tree::Branches>(item_id, tree, [&]{ return match_level2(tree, item_id, f2, fs...); } );
		return f.apply(item_id, tree, [&]{ return match_level2(tree, item_id, f2, fs...); } );
		
		//if( f.is_in(typename Tree::Branches(), item_id) )
		//{
		//	return f.apply(tree);
		//}
		//else{ return match_level2(tree, item_id, f2, fs...); }
	}

	//-------------------------------------------

	//First level: select branch list based on BranchId of the TreeNode:
	template<typename T, typename Brs, typename Ann, int k, typename F>
	auto match_level1(TreeNode<T, Brs, Ann> const& tree, uint32_t const& list_id, uint32_t const& item_id, Int<k> const&, F&& f)
	{
		//Current Target Branch:
		auto br = typename TreeNode<T, Brs, Ann>::Branches::List()[Int<k>()];
		//Count the handlers of all tags in the current branch:
		auto m = map( [&](auto e){ return f.count_handlers_of(e); }, typename decltype(br)::List() );
		//Calculate the product of handlers over all the current branch, must be 1:
		auto res = product(m);
		static_assert( decltype(res)::value >= 1, "Totality check failed in match. One or more tags are not handled in a Matcher");
		static_assert( decltype(res)::value <= 1, "Unicity check failed in match. One or more tags are multiply handled in a Matcher");

		return f.match(tree, item_id);
		return f.match(tree, item_id);
	}

	template<typename T, typename Brs, typename Ann, int n, typename F, typename F2, typename... Fs>
	auto match_level1(TreeNode<T, Brs, Ann> const& tree, uint32_t const& list_id, uint32_t const& item_id, Int<n> const&, F&& f, F2&& f2, Fs&&... fs)
	{
		if( list_id == n )
		{
			//Current Target Branch:
			auto br = typename TreeNode<T, Brs, Ann>::Branches::List()[Int<n>()];
			//Count the handlers of all tags in the current branch:
			auto m = map( [&](auto e){ return f.count_handlers_of(e); }, typename decltype(br)::List() );
			//Calculate the product of handlers over all the current branch, must be 1:
			auto res = product(m);
			static_assert( decltype(res)::value >= 1, "Totality check failed in match. One or more tags are not handled in a Matcher");
			static_assert( decltype(res)::value <= 1, "Unicity check failed in match. One or more tags are multiply handled in a Matcher");

			return f.match(tree, item_id);
		}
		else{ return match_level1(tree, list_id, item_id, Int<n+1>(), f2, fs...); }
	}
}

template<typename T, typename Tree> struct TaggedTree
{
	Tree tree;
	T tag;

	auto& operator[](int i)const{ return tree[i]; }
	auto& operator[](int i)     { return tree[i]; }

	int size() const { return (int)tree.chs.size(); }

	auto& ann() const { return tree.ann; }
	auto& ann()       { return tree.ann; }
};

template<typename T, typename Tree>
auto taggedTree(Tree&& tree){ return TaggedTree<T, Bare<Tree>>{ std::forward<Tree>(tree) }; }

//A list of Cases to match for, and execute the stored function on the tree: 
template<typename F, typename... Cases> struct Resolver
{
	using List = TyList<Cases...>;
	F f;

	template<typename B>
	auto is_in( B const& b ) const
	{ 
		return select( is_same_type( index_of_type(b, Int<-1>(), List()), Int<-1>() ), Int<0>(), Int<1>() );
	}

	//Check if the runtime branch item is any of the stored Cases:
	template<typename Brl>
	bool is_in( Brl const& brl, uint32_t const& item_id ) const
	{
		return or_all( map( [=](auto c){ return brl.lookup(c).item_id() == item_id; }, tup(Cases()...)) );
	}

	template<typename Tree>	auto operator()(Tree const& tree) const { return f(tree); }

	template<typename Case, typename Tree> auto invoke(Tree const& tree) const { return f( taggedTree<typename Case::Tag>(tree) ); }

	template<typename Tree, typename FCont, typename Tagidx>
	auto apply_one(uint32_t const& item_id, Tree const& tree, FCont const& fcont, Tagidx const&) const
	{
		if( Tagidx::Idx::value == item_id ){ return invoke<Tagidx>(tree); }
		else{ return fcont(); }
	}

	template<typename Tree, typename FCont, typename Tagidx, typename C2, typename... Cs>
	auto apply_one( uint32_t const& item_id, Tree const& tree, FCont const& fcont, Tagidx const&, C2 const& c2, Cs const& ... cases ) const
	{
		if( Tagidx::Idx::value == item_id ){ return invoke<Tagidx>(tree); }
		else{ return apply_one(item_id, tree, fcont, c2, cases...); }
	}

	template<typename Tree, typename FCont>
	auto apply(uint32_t const& item_id, Tree const& tree, FCont const& fcont) const
	{
		return apply_one(item_id, tree, fcont, tree.branch_list().lookup_item(Cases())... );
	}

	//----------------------

	template<typename Tree, typename Tagidx>
	auto apply_end_one( uint32_t const& item_id, Tree const& tree, Tagidx const& ) const
	{
		if( Tagidx::Idx::value != item_id ){ std::cout << "Match error\n"; }
		return invoke<Tagidx>(tree);
	}

	template<typename Tree, typename Tagidx, typename C2, typename... Cs>
	auto apply_end_one(uint32_t const& item_id, Tree const& tree, Tagidx const&, C2 const& c2, Cs const& ... cases ) const
	{
		if( Tagidx::Idx::value == item_id ){ return invoke<Tagidx>(tree); }
		else{ return apply_end_one(item_id, tree, c2, cases...); }
	}

	template<typename Tree>
	auto apply_end(uint32_t const& item_id, Tree const& tree) const
	{
		return apply_end_one(item_id, tree, tree.branch_list().lookup_item(Cases())... );
	}
};

auto repeat_last_letter( std::string const& str )
{
	if(str.size() > 0){ return str + str[str.size()-1]; }
	return str;
}

//Helper macro to define end user branch tags:
#define Tag(x) struct x{ using IsTag = True; operator std::string() const { return #x; } };

//SFINAE helper to discriminate tags from other types:
template<typename T, typename R = void> struct IsNotTag{ using Res = True; };
template<typename T> struct IsNotTag<T, typename Void<typename T::IsTag>::type>;

//template<typename T> using GetTag = typename T::Tag;
//template<typename T> using IsNotTag = typename Not< typename Is<Bare<T>, GetTag>::Res >::Res;
//template<typename T> using IsTag    = typename Is<T, GetTag>::Res;

template<typename Tag1, typename Tag2, typename Req1 = typename Tag1::IsTag, typename Req2 = typename Tag2::IsTag>
auto operator == ( Tag1 const& t1, Tag2 const& t2 ){ return is_same_type(t1, t2); }

//Selector storing Cases:
template<typename... Cases> struct Selector{};

//Helpers to construct Resolvers from Tags, Selectors and Functions:
template<typename... Cases, typename F>
auto Resolver_helper( Selector<Cases...> const&, F&& f, typename IsNotTag<F>::Res* p = nullptr ){ return Resolver<Bare<F>, Cases...>{std::forward<F>(f)}; }

template<typename... Cases, typename T>
auto Resolver_helper( Selector<Cases...> const&, T&& t, typename T::IsTag* p = nullptr ){ return Selector<Cases..., Bare<T>>(); }

template<typename Tag, typename F>
auto Resolver_helper( Tag const&, F&& f, typename Tag::IsTag* p = nullptr, typename IsNotTag<F>::Res* q = nullptr ){ return Resolver<Bare<F>, Tag>{std::forward<F>(f)}; }
//auto Resolver_helper( Tag const&, F&& f, typename Tag::IsTag* p = nullptr, IsNotTag<F>* q = nullptr ){ return Resolver<Bare<F>, Tag>{std::forward<F>(f)}; }

template<typename Tag, typename T>
auto Resolver_helper( Tag const&, T&& t, typename Tag::IsTag* p = nullptr, typename T::IsTag* q = nullptr ){ return Selector<Tag, Bare<T>>(); }

template<typename... Cases, typename F>
auto operator | ( Selector<Cases...> const& s, F&& f ){ return Resolver_helper(s, std::forward<F>(f)); }

template<typename Tag, typename F, typename Rq = decltype(typename Tag::IsTag())>
auto operator | ( Tag const& t, F&& f ){ return Resolver_helper(t, std::forward<F>(f)); }

//template<typename... Cases, typename F, typename Req = typename IsNotTag<F>::Res>
//auto operator | ( Selector<Cases...> const&, F&& f ){ return Resolver<Bare<F>, Cases...>{std::forward<F>(f)}; }

/*template<typename Tag, typename F, typename Req1 = typename Tag::IsTag, typename Req2 = typename IsNotTag<F>::Res>
auto operator | ( Tag const&, F&& f ){ return Resolver<Bare<F>, Tag>{std::forward<F>(f)}; }

template<typename Tag1, typename Tag2, typename Req1 = typename Tag1::IsTag, typename Req2 = typename Tag2::IsTag>
auto operator | ( Tag1 const&, Tag2 const& ){ return Selector<Tag1, Tag2>(); }*/

/*template<typename Tag, typename F, typename Req1 = typename Tag::IsTag, typename Req2 = typename IsNotTag<F>::Res>
auto operator | ( Tag const&, F&& f ) -> decltype( typename Tag::IsTag(), typename IsNotTag<F>::Res(), Resolver<Bare<F>, Tag>{std::forward<F>(f)} ){ return Resolver<Bare<F>, Tag>{std::forward<F>(f)}; }

template<typename Tag1, typename Tag2, typename R = Selector<Tag1, Tag2>>//, typename Req1 = typename Tag1::IsTag, typename Req2 = typename Tag2::IsTag>
auto operator | ( Tag1 const&, Tag2 const& ) -> decltype(typename Tag1::IsTag(), typename Tag2::IsTag(), R()){ return Selector<Tag1, Tag2>(); }
*/
//template<typename Tag, typename Req = typename Tag::IsTag, typename... Tags>
//auto operator | ( Selector<Tags...> const&, Tag const& ){ return Selector<Tags..., Tag>(); }

//Matcher is a handler for the first level of the branch hierarchy, storing Resolvers for a BranchList:
template<typename... Rs> struct Matcher
{
	Tuple<Rs...> rs;

	template<typename B> auto count_handlers_of(B const& b) const
	{
		return sum( map( [&](auto const& r){ return r.is_in( b ); }, rs ) );
	};

	template<typename Tree, typename... Is>
	auto my_match_proxy(Tree const& tree, uint32_t const& item_id, Integers<Is...> const&) const
	{
		return detail::match_level2(tree, item_id, rs[Is()]...);
	}

	template<typename Tree>
	auto match(Tree const& tree, uint32_t const& item_id) const
	{
		return my_match_proxy(tree, item_id, SeqTo<Rs...>());
	}
};

//Helper to construct a Matcher:
template<typename... Fs>
auto matcher(Fs&&... fs){ return Matcher<Fs...>{ tup(fs...) }; }

//Start matching a TreeNode against a set of Matchers:
template<typename T, typename... Brs, typename Ann, typename... Ms>
auto match(TreeNode<T, BranchList<Brs...>, Ann> const& tree, Ms&&... ms)
{
	static_assert( sizeof...(Ms) == sizeof...(Brs), "The number of BranchLists does not match the number of Matchers in TreeNode match." );
	return detail::match_level1(tree, tree.branch.list_id(), tree.branch.item_id(), Int<0>(), ms...);
}

//-------------------------
// Begin of End-User Code
//-------------------------

//Define the branch ids for our sum type:
namespace Tags
{
	Tag(Symbol)
	Tag(Lambda);
	Tag(App);
	Tag(Map);
	Tag(Zip);
	Tag(Rnz);
	Tag(Star);
}

struct NodeData
{
	NodeData():data{}, level{-1}{}
	NodeData( const char* s ):data{s}, level{-1}{}
	NodeData( std::string const& s ):data{s}, level{-1}{}
	NodeData( std::string &&     s ):data{std::move(s)}, level{-1}{}
	NodeData( std::string const& s, int lvl ):data{s}, level{lvl}{}
	NodeData( NodeData const& nd ):data{nd.data}, level{nd.level}{}
	std::string data;
	int level;

	operator std::string() const { return data + (level >= 1 ? std::to_string(level) : std::string()); } 
};

//Define the Branch Lists for the two cases: normal AST and the Pattern tree:
struct ASTNodes     : BranchBase< TyList< Tags::Symbol, Tags::Lambda, Tags::App, Tags::Map, Tags::Zip, Tags::Rnz> >{};
struct PatternNodes : BranchBase< TyList< Tags::Star > >{};

using ASTBranchList     = BranchList< ASTNodes >;
using PatternBranchList = BranchList< ASTNodes, PatternNodes >;

//And now the specific tree defs:
using AST         = Fix<TreeNode, ASTBranchList,     NodeData>;
using PatternTree = Fix<TreeNode, PatternBranchList, NodeData>;

//Helpers for building an AST:
namespace ast
{
	auto Symbol = from_str<ASTBranchList, Tags::Symbol, NodeData>();
	auto Lambda = from_chs<ASTBranchList, Tags::Lambda, NodeData>();
	auto App    = from_chs<ASTBranchList, Tags::App, NodeData>();
	auto Map    = from_chs<ASTBranchList, Tags::Map, NodeData>();
	auto Zip    = from_chs<ASTBranchList, Tags::Zip, NodeData>();
	auto Rnz    = from_chs<ASTBranchList, Tags::Rnz, NodeData>();

	auto Build = from_childsof<ASTBranchList, NodeData>();

	auto operator"" _sym ( const char* s, size_t sz  ){ return Symbol(s); }

	auto Sym( std::string const& s, int level  ){ return Symbol( NodeData{s, level} ); }
}

//Helpers for building a Pattern Tree:
namespace patterns
{
	auto Symbol = from_str<PatternBranchList, Tags::Symbol, NodeData>();
	auto Lambda = from_chs<PatternBranchList, Tags::Lambda, NodeData>();
	auto App    = from_chs<PatternBranchList, Tags::App, NodeData>();
	auto Map    = from_chs<PatternBranchList, Tags::Map, NodeData>();
	auto Zip    = from_chs<PatternBranchList, Tags::Zip, NodeData>();
	auto Rnz    = from_chs<PatternBranchList, Tags::Rnz, NodeData>();

	auto Star = from_str<PatternBranchList, Tags::Star, NodeData>();
	auto Build = from_childsof<PatternBranchList, NodeData>();

	auto operator"" _sym ( const char* s, size_t sz ){ return Symbol(s); }

	auto Sym( std::string const& s, int level  ){ return Symbol( NodeData{s, level} ); }
}

//This is a completely different Match than any of the earlier:D
//Stores the resolution of the 'Star' placeholders
template<typename TreeType>
struct Match
{
	std::map<std::string, TreeType> data;

	Match( std::string const& id, TreeType const& tree ){ data.insert(std::make_pair(id, tree)); }
	Match( Match const& m1, Match const& m2 )                                  { data.insert(m1.data.begin(), m1.data.end()); data.insert(m2.data.begin(), m2.data.end()); }
	Match( Match const& m1, Match const& m2, Match const& m3 )                 { data.insert(m1.data.begin(), m1.data.end()); data.insert(m2.data.begin(), m2.data.end()); data.insert(m3.data.begin(), m3.data.end()); }
	Match( Match const& m1, Match const& m2, Match const& m3, Match const& m4 ){ data.insert(m1.data.begin(), m1.data.end()); data.insert(m2.data.begin(), m2.data.end()); data.insert(m3.data.begin(), m3.data.end()); data.insert(m4.data.begin(), m4.data.end());}
	Match(){}

	TreeType const& operator[](std::string const& key) const { return data.at(key); }
};

//Elgot coalgebraic part: compares an AST to a Pattern Tree, stores matches against 'Star' in a Maybe<Match>
//makeComp :: (Expr, PExpr) -> Either (Maybe Match) (ExprF (Expr, PExpr))
//makeComp (Fix (Func s1), Fix (PFunc s2)) | s1 == s2 = Right $ Func s1
//makeComp (Fix (Add a1 b1), Fix (PAdd a2 b2))        = Right $ Add (a1,a2) (b1,b2)
//makeComp (Fix (Mul a1 b1), Fix (PMul a2 b2))        = Right $ Mul (a1,a2) (b1,b2)
//makeComp (Fix (Diff a1), Fix (PDiff a2))            = Right $ Diff (a1,a2)
//makeComp (subTree, Fix (PStar id))                  = Left $ Just $ M.singleton id subTree
//makeComp _                                          = Left Nothing
Either<Maybe<Match<AST>>, TreeNode<std::pair<AST, PatternTree>, ASTBranchList, NodeData>> makeComp( std::pair<AST, PatternTree> const& inp)
{
	using Left  = Maybe<Match<AST>>;
	using Right = TreeNode<std::pair<AST, PatternTree>, ASTBranchList, NodeData>;
	auto tree = unfix( inp.first );
	auto pattern = unfix( inp.second );
	if     ( is_same_branch(tree, pattern, Tags::Symbol()) &&
		     tree.ann.data == pattern.ann.data                 ){ return Right(Tags::Symbol(), tree.ann); }
	else if( is_same_branch(tree, pattern, Tags::Lambda() )    ){ return Right(Tags::Lambda(), {}, std::make_pair(tree[0], pattern[0]), std::make_pair(tree[1], pattern[1])); }
	else if( is_same_branch(tree, pattern, Tags::App() )       ){ return Right(Tags::App(),    {}, std::make_pair(tree[0], pattern[0]), std::make_pair(tree[1], pattern[1])); }
	else if( is_same_branch(tree, pattern, Tags::Map())        ){ return Right(Tags::Map(),    {}, std::make_pair(tree[0], pattern[0]), std::make_pair(tree[1], pattern[1])); }
	else if( is_same_branch(tree, pattern, Tags::Zip())        ){ return Right(Tags::Zip(),    {}, std::make_pair(tree[0], pattern[0]), std::make_pair(tree[1], pattern[1]), std::make_pair(tree[2], pattern[2])); }
	else if( is_same_branch(tree, pattern, Tags::Rnz())        ){ return Right(Tags::Rnz(),    {}, std::make_pair(tree[0], pattern[0]), std::make_pair(tree[1], pattern[1]), std::make_pair(tree[2], pattern[2]), std::make_pair(tree[3], pattern[3])); }
	else if( is_same_branch(pattern, Tags::Star()) ){ return Left( Just(), Match<AST>( pattern.ann.data, inp.first ) ); }
	else{ return Left( Nothing() ); }
}

//Elgot algebraic part: merge Matches
//evalComp :: ExprF (Maybe Match) -> Maybe Match
//evalComp (Func _)                = Just M.empty
//evalComp (Add (Just a) (Just b)) = Just $ M.union a b
//evalComp (Mul (Just a) (Just b)) = Just $ M.union a b
//evalComp (Diff a)                = a
//evalComp _                       = Nothing
Maybe<Match<AST>> evalComp( TreeNode<Maybe<Match<AST>>, ASTBranchList, NodeData> const& tree )
{
	return match(tree, matcher( Tags::Symbol()                             | [](auto&&  ){ return just( Match<AST>() ); },
		                        Tags::Lambda() | Tags::App() | Tags::Map() | [](auto&& t){ return t[0] && t[1] ? just( Match<AST>(t[0].value, t[1].value) ) : Nothing(); },
		                        Tags::Zip()                                | [](auto&& t){ return t[0] && t[1] && t[2] ? just( Match<AST>(t[0].value, t[1].value, t[2].value) ) : Nothing(); },
								Tags::Rnz()                                | [](auto&& t){ return t[0] && t[1] && t[2] && t[3]? just( Match<AST>(t[0].value, t[1].value, t[2].value, t[3].value) ) : Nothing(); }));
		        
}

//Rebuild a replacement pattern tree into an AST, substituting 'Star's with their resolutions from Match:
//fillReplacement :: Match -> PExpr -> Expr
//fillReplacement match = cata fillAlg where
//    fillAlg (PFunc s)  = func s
//    fillAlg (PAdd a b) = add a b
//    fillAlg (PMul a b) = mul a b
//    fillAlg (PDiff a)  = diff a
//    fillAlg (PStar id) = match M.! id

AST fillReplacement( Match<AST> const& m, PatternTree const& tree )
{
	auto alg = alg_helper<AST>( matcher( Tags::Symbol() | [ ](auto&& sub){ return ast::Symbol(sub.ann()); },
									     Tags::Lambda() | Tags::App () | Tags::Map() | Tags::Zip() | Tags::Rnz() | [ ](auto&& sub){ return ast::Build(sub); } ),
		                        matcher( Tags::Star() | [&](auto&& sub){ return m[sub.ann().data]; } ) );
	return cata(alg, tree);
}

template<typename FTr>
AST fillReplacementWithTransform( Match<AST> const& m, PatternTree const& tree, FTr&& ftr )
{
	auto alg = alg_helper<AST>( matcher( Tags::Symbol() | [ ](auto&& sub){ return ast::Symbol(sub.ann()); },
									     Tags::Lambda() | Tags::App () | Tags::Map() | Tags::Zip() | Tags::Rnz() | [ ](auto&& sub){ return ast::Build(sub); } ),
		                        matcher( Tags::Star() | [&](auto&& sub)->AST{ return ftr(sub, m); } ) );
	return cata(alg, tree);
}

//Repeat replacements for all occurances of pattern bottom-up:
//replaceAll :: PExpr -> PExpr -> Expr -> Expr
//replaceAll pat rep = cata replace where
//    replace node =
//        case elgot evalComp makeComp (Fix node, pat) of
//            (Just m) -> fillReplacement m rep
//            Nothing  -> Fix node

AST replaceAll( PatternTree const& pattern, PatternTree const& replacement, AST const& tree )
{
	auto replace = [&]( auto&& node )
	{
		auto res = elgot( alg<Maybe<Match<AST>>>(evalComp), elgotCoalgSwitch<TreeNode, ASTBranchList, NodeData>(makeComp), std::make_pair(fix(node), pattern) );
		if( res.exists )
		{
			return fillReplacement(res.value, replacement);
		}
		else{ return fix(node); }
	};
	return cata( alg<AST>(replace), tree);
}

//Constraint helper in the replacement:
template<typename NodeType, typename FConstr, typename N>
struct Constraint
{
	FConstr f;
	std::array<NodeType, N::value> inputs;
	
	template<typename ReplacementNodeType>
	bool operator()( Match<ReplacementNodeType> const& match ) const
	{
		std::array<ReplacementNodeType, N::value> res;
		for(int i=0; i<N::value; ++i)
		{
			res[i] = match.data.at( unfix( inputs[i] ).ann.data );
		}
		return expand<N>(f, res);
	}
};

template<typename F, typename Arg0, typename... Args>
auto constraint(F&& f, Arg0&& arg0, Args&&... args)
{
	return Constraint<Bare<Arg0>, Bare<F>, Int<sizeof...(Args)+1>>{ std::forward<F>(f), {std::forward<Arg0>(arg0), std::forward<Args>(args)... } };
}

template<typename Pattern, typename FGlobal>
AST replaceAllOfPattern( AST const& tree, Pattern&& p, FGlobal&& fg )
{
	auto replace = [&]( auto&& node )
	{
		//Res is a Maybe<Match<AST>>
		auto res = elgot( alg<Maybe<Match<AST>>>(evalComp), elgotCoalgSwitch<TreeNode, ASTBranchList, NodeData>(makeComp), std::make_pair(fix(node), p.pattern) );
		//if stores value and constraints evaluate to true, do replacement:
		if( res.exists )
		{
			return fg(p.apply(res.value, fix(node)), res.value);
		}
		else{ return fix(node); }
	};
	return cata( alg<AST>(replace), tree);
}

template<typename Pattern, typename FGlobal>
AST replaceAllOfPatternDown( AST const& tree, Pattern&& p, FGlobal&& fg )
{
	auto replace = [&]( auto&& node )
	{
		//Res is a Maybe<Match<AST>>
		auto res = elgot( alg<Maybe<Match<AST>>>(evalComp), elgotCoalgSwitch<TreeNode, ASTBranchList, NodeData>(makeComp), std::make_pair((node), p.pattern) );
		//if stores value and constraints evaluate to true, do replacement:
		/*if( res.exists )
		{
			return fg(p.apply(res.value, fix(node)), res.value);
		}
		else{ return fix(node); }*/
		if( res.exists )
		{
			return unfix(fg(p.apply(res.value, id(node)), res.value));
		}
		else{ return unfix(node); }
	};
	//return cata( alg<AST>(replace), tree);
	return ana( coalg<TreeNode, ASTBranchList, NodeData>(replace), tree);
}

template<typename Pattern, typename FPattern, typename FGlobal>
AST replaceOneOfPattern( AST const& tree, Pattern&& p, FPattern&& fp, FGlobal&& fg )
{
	//static_assert( Has Bare<Pattern>::IsPattern::value, "p is not a pattern!" );
	bool did_one = false;
	Maybe<Match<AST>> m;
	auto replace = [&]( auto&& node )
	{
		if(did_one){ return fix(node); }
		//Res is a Maybe<Match<AST>>
		m = elgot( alg<Maybe<Match<AST>>>(evalComp), elgotCoalgSwitch<TreeNode, ASTBranchList, NodeData>(makeComp), std::make_pair(fix(node), p.pattern) );
		//if stores value and constraints evaluate to true, do replacement:
		if( m.exists )
		{
			did_one = true;
			return fp(p.apply(m.value, fix(node)), m.value);
		}
		else{ return fix(node); }
	};
	auto tmp = cata(alg<AST>(replace), tree);
	return m ? fg(tmp, m.value) : tmp;
}

template<typename Pattern, typename FPattern, typename FGlobal>
AST replaceOneOfPatternDown( AST const& tree, Pattern&& p, FPattern&& fp, FGlobal&& fg )
{
	//static_assert( Has Bare<Pattern>::IsPattern::value, "p is not a pattern!" );
	bool did_one = false;
	Maybe<Match<AST>> m;
	auto replace = [&]( auto&& node )
	{
		if(did_one){ return unfix(node); }
		//Res is a Maybe<Match<AST>>
		m = elgot( alg<Maybe<Match<AST>>>(evalComp), elgotCoalgSwitch<TreeNode, ASTBranchList, NodeData>(makeComp), std::make_pair((node), p.pattern) );
		//if stores value and constraints evaluate to true, do replacement:
		if( m.exists )
		{
			did_one = true;
			return unfix(fp(p.apply(m.value, id(node)), m.value));
		}
		else{ return unfix(node); }
	};
	auto tmp = ana( coalg<TreeNode, ASTBranchList, NodeData>(replace), tree);
	return m ? fg(tmp, m.value) : tmp;
}

template<typename Pattern, typename FPattern, typename FGlobal>
AST replaceNthHoFPatternDown( AST const& tree, int n, Pattern&& p, FPattern&& fp, FGlobal&& fg )
{
	int count = 0;
	Maybe<Match<AST>> m;
	auto replace = [&]( auto&& node )
	{
		if(n < count){ return unfix(node); }
		bool isHoF = node.is_branch(Tags::Map()) || node.is_branch(Tags::Zip()) || node.is_branch(Tags::Rnz());
		if( isHoF )
		{
			count++;
			if(count-1 == n)
			{
				//Res is a Maybe<Match<AST>>
				m = elgot( alg<Maybe<Match<AST>>>(evalComp), elgotCoalgSwitch<TreeNode, ASTBranchList, NodeData>(makeComp), std::make_pair((node), p.pattern) );
				//if stores value and constraints evaluate to true, do replacement:
				if( m.exists )
				{
					return unfix(fp(p.apply(m.value, id(node)), m.value));
				}
			}
		}
		return unfix(node);
	};
	auto tmp = ana( coalg<TreeNode, ASTBranchList, NodeData>(replace), tree);
	return m ? fg(tmp, m.value) : tmp;
}

template<typename FGlobal, typename... Patterns>
AST replaceAllOfPatterns( AST const& tree, FGlobal&& fg, Patterns&&... ps )
{
	return foldl( [&](auto&& t, auto&& p){ return replaceAllOfPattern(t, p, fg); }, tree, tup(ps...) );
}

template<typename FGlobal, typename... Patterns>
AST replaceAllOfPatternsDown( AST const& tree, FGlobal&& fg, Patterns&&... ps )
{
	return foldl( [&](auto&& t, auto&& p){ return replaceAllOfPatternDown(t, p, fg); }, tree, tup(ps...) );
}

template<typename FTr, typename... Constrs>
struct Replacer
{
	PatternTree       replacement;
	FTr               transformation;
	Tuple<Constrs...> constraints;

	template<typename ASTType>
	bool eval_constraints(Match<ASTType> const& m) const
	{
		return rnz(And, [&](auto&& c){ return c(m); }, True(), constraints);
		//return and_all( map( [&](auto&& c){ return c(m); }, constraints ) );
		//return foldl([&](auto const& b, auto const& r){ return b && r(m); }, True(), constraints);
		//return expand<Int<sizeof...(Constrs)>>( [&](auto&&... xs){ return foldl_pack(And, xs(m)...); }, constraints ); 
	}

	template<typename ASTType>
	auto applyReplacer(Match<ASTType> const& m) const
	{
		return fillReplacementWithTransform(m, replacement, transformation);
	}
};

template<typename FTr, typename... Constrs>
auto replacer(PatternTree const& replacement_, FTr&& ftr, Constrs&&... constrs)
{
	return Replacer<Bare<FTr>, Bare<Constrs>...>{ replacement_, std::forward<FTr>(ftr), tup( std::forward<Constrs>(constrs)... ) };
}

template<typename FTr, typename... Constrs>
struct Pattern
{
	using IsPattern = True;
	PatternTree pattern;
	PatternTree replacement;
	FTr         transformation;
	Tuple<Constrs...> constraints;

	template<typename ASTType>
	auto apply(Match<ASTType> const& m, ASTType&& default_res)
	{
		if( eval_constraints(m) )
		{
			return fillReplacementWithTransform(m, replacement, transformation);
		}
		else{ return default_res; }
	}

	template<typename ASTType>
	bool eval_constraints(Match<ASTType> const& m) const
	{
		//return expand<Int<sizeof...(Constrs)>>( [&](auto&&... xs){ return foldl_pack(And, xs(m)...); }, constraints );
		//return expand<Int<sizeof...(Constrs)>>( [&](auto&&... xs){ return and_all( tup(xs(m)...) ); }, constraints );
		//return and_all( map( [](auto&& c){ return c(m); }, constraints ) );
		return rnz(And, [&](auto&& c){ return c(m); }, True(), constraints);
	}
};

auto pattern(PatternTree const& pattern_, PatternTree const& replacement_){ return Pattern<decltype(leftid)>{pattern_, replacement_, leftid, {Constructor{}}}; }
template<typename FTr, typename... Constrs>
auto pattern(PatternTree const& pattern_, PatternTree const& replacement_, FTr&& ftr, Constrs&&... constrs){ return Pattern<Bare<FTr>, Bare<Constrs>...>{pattern_, replacement_, std::forward<FTr>(ftr), { Constructor{}, std::forward<Constrs>(constrs)... } }; }

template<typename... Replacers>
struct PatternFamily
{
	using IsPattern = True;
	PatternTree         pattern;
	Tuple<Replacers...> replacers;

	template<typename ASTType>
	auto apply(Match<ASTType> const& m, ASTType&& default_res)
	{
		auto folder = [&]( auto const& pacc, auto const& r )
		{
			if( pacc.first )
			{
				return pacc;
			}
			else if(r.eval_constraints(m))
			{
				return std::make_pair(true, r.applyReplacer(m));
			}
			else
			{
				return pacc;
			}
		};
		//return expand<Int<sizeof...(Replacers)>>( [&](auto&&... rs){ return foldl_pack( folder, std::make_pair(false, default_res), rs... ); }, replacers ).second;
		//return expand<Int<sizeof...(Replacers)>>( [&](auto&&... rs){ return foldl( folder, std::make_pair(false, default_res), rs... ); }, replacers ).second;
		return foldl( folder, std::make_pair(false, default_res), replacers ).second;
	}
};

template<typename... Replacers>
auto patternfamily(PatternTree const& pattern_, Replacers&&... repls){ return PatternFamily<Bare<Replacers>...>{pattern_, tup( std::forward<Replacers>(repls)... ) }; }

auto merge_names( std::vector<std::set<std::string>> const& v)
{
	std::set<std::string> names;
	for(auto&& e : v){ names.insert(e.begin(), e.end()); }
	return names;
}

using Set = std::set<std::string>;

auto merge_names( Set const& s1, Set const& s2 )
{
	std::set<std::string> names;
	for(auto&& e : s1){ names.insert(s1.begin(), s1.end()); }
	for(auto&& e : s2){ names.insert(s2.begin(), s2.end()); }
	return names;
}

auto ordered_merge_names( std::vector<Set>&& previous, Set const& newdata)
{
	//Set x;
	//x.insert(newdata.begin(), newdata.end());
	//previous.push_back(newdata);
	previous.insert(previous.begin(), newdata);
	return previous;
}

auto subtract_names( std::set<std::string>&& all, std::vector<std::string> const& names )
{
	for(auto const& n : names){ all.erase(n); } return all;
}

auto& operator<<( std::ostream& os, std::set<std::string> const& names )
{
	os << "set:";
	for(auto const& x : names)
	{
		os << " " << x;
	}
	return os;
}

auto& operator<<( std::ostream& os, std::vector<std::set<std::string>> const& names )
{
	os << "vector: ";
	for(auto const& x : names)
	{
		os << "[" << x << "]";
	}
	return os;
}

template<typename T>
auto para_ch_ann(T&& tree, int idx){ return unfix(fw(T, tree)[idx].second).ann; }

std::vector<int> UpTo(int n, int offset = 0)
{
	std::vector<int> retval(n);
	for (int ii = 0; ii < n; ++ii){ retval[ii] = ii + offset; }
	return retval;
}

//source: https://rosettacode.org/wiki/Permutations_by_swapping#C.2B.2B

struct JohnsonTrotterState_
{
	std::vector<int> values_;
	std::vector<int> positions_;	// size is n+1, first element is not used
	std::vector<bool> directions_;
	int sign_;
 
	JohnsonTrotterState_(int n) : values_(UpTo(n, 1)), positions_(UpTo(n + 1, -1)), directions_(n + 1, false), sign_(1) {}
 
	int LargestMobile() const	// returns 0 if no mobile integer exists
	{
		for (int r = values_.size(); r > 0; --r)
		{
			const int loc = positions_[r] + (directions_[r] ? 1 : -1);
			if (loc >= 0 && loc < values_.size() && values_[loc] < r){ return r; }
		}
		return 0;
	}
 
	bool IsComplete() const { return LargestMobile() == 0; }
 
	int operator++()	// implement Johnson-Trotter algorithm
	{
		const int r = LargestMobile();
		const int rLoc = positions_[r];
		const int lLoc = rLoc + (directions_[r] ? 1 : -1);
		const int l = values_[lLoc];
		// do the swap
		std::swap(values_[lLoc], values_[rLoc]);
		std::swap(positions_[l], positions_[r]);
		sign_ = -sign_;
		// change directions
		for (auto pd = directions_.begin() + r + 1; pd != directions_.end(); ++pd){ *pd = !*pd; }

		return std::max(lLoc, rLoc);
	}
};

int main()
{
	//std::string s = "int main()\n{\n\tint i=0;\n\treturn x;\n}\n";

	auto indent = [](std::string const& s)
	{
		size_t o = 0;
		std::string res = s;
		while(o <= res.size())
		{
			size_t p = 0;
			if( (p = res.find("\t", o)) != std::string::npos )
			{
				res.insert(p, "   ");
				o = p + 5;
			}
			else{ break; }
		}
		
		return res;
	};

	auto remove_tabs = [](std::string&& s){ s.erase(std::remove(s.begin(), s.end(), '\t'), s.end()); return s; };

	auto remove_upto_closing_paren = [](auto&& s){ return s.substr(s.find_first_of(')')); };
	//std::cout << indent(s) << "\n";

	//return 0;
	auto ASTPrintmatcher = matcher( Tags::Symbol() | [](auto&& sub){ return (std::string)sub.ann(); },
							        Tags::Lambda() | [](auto&& sub){ return std::string("(\\")   + sub[0] + "." + sub[1] + ")"; },
									Tags::App()    | [](auto&& sub){ return std::string("(")     + sub[0] + " " + sub[1] + ")"; },
									Tags::Map()    | [](auto&& sub){ return std::string("map ") + sub[0] + " " + sub[1]; },
							        Tags::Zip()    | [](auto&& sub){ return std::string("zip ") + sub[0] + " " + sub[1] + " " + sub[2]; },
	                                Tags::Rnz()    | [](auto&& sub){ return std::string("rnz ") + sub[0] + " " + sub[1] + " " + sub[2] + " " + sub[3] + ""; } );
	auto ast_print = alg_helper<std::string>( ASTPrintmatcher );
	auto pattern_print = alg_helper<std::string>( ASTPrintmatcher, matcher( Tags::Star() |  [](auto&& sub){ return std::string("'") + sub.data() + "'"; } ) );
	auto print = [&](auto&& t){ return cata(ast_print, t); };

	//---------------------------------------------------

	auto fill_hof_rank = [](auto&& tree)
	{
		auto m = matcher( Tags::Symbol() | [](auto&& sub){ return ast::Symbol(sub.ann()); },
			              Tags::Lambda() | [](auto&& sub){ return build_node( ASTBranchList(), Tags::Lambda(), NodeData{"", para_ch_ann(sub, 1).level}, sub[0].second, sub[1].second); },
		                  Tags::App()    | [](auto&& sub)
										   {
											  auto lvl = para_ch_ann(sub, 0).data == "lift" ? para_ch_ann(sub, 1).level+1: para_ch_ann(sub, 0).level;
											  return build_node( ASTBranchList(), Tags::App(), NodeData{"", lvl}, sub[0].second, sub[1].second);
		                                   },
		                  Tags::Map()    | [](auto&& sub){ return build_node( ASTBranchList(), Tags::Map(), NodeData{"", para_ch_ann(sub, 0).level + 1}, sub[0].second, sub[1].second); },
		                  Tags::Zip()    | [](auto&& sub){ return build_node( ASTBranchList(), Tags::Zip(), NodeData{"", para_ch_ann(sub, 0).level + 1}, sub[0].second, sub[1].second, sub[2].second); },
		                  Tags::Rnz()    | [](auto&& sub){ return build_node( ASTBranchList(), Tags::Rnz(), NodeData{"", para_ch_ann(sub, 0).level    }, sub[0].second, sub[1].second, sub[2].second, sub[3].second); } );
		return para(alg_helper<AST>(m), lfw(tree));
	};

	//---------------------------------------------------

	auto collect_dependency_string = [](auto&& tree)
	{
		struct Collection
		{
			std::vector<Set> merged;
			Set              nonmerged;
		};

		auto m = matcher( Tags::Symbol() | [](auto&& sub){ return Collection{ {}, {(std::string)sub.ann()} }; },
                          Tags::Lambda() | [](auto&& sub){ return sub[1]; },
		                  Tags::App()    | [](auto&& sub){ return sub[0]; },
			              Tags::Map()    | [](auto&& sub){ return Collection{ ordered_merge_names(std::move(sub[0].merged), merge_names(sub[0].nonmerged, sub[1].nonmerged)), {} }; },
		                  Tags::Zip()    | [](auto&& sub){ return Collection{ ordered_merge_names(std::move(sub[0].merged), merge_names(sub[0].nonmerged, sub[1].nonmerged)), {} }; },
		                  Tags::Rnz()    | [](auto&& sub){ return Collection{ ordered_merge_names(std::move(sub[1].merged), merge_names(sub[2].nonmerged, sub[3].nonmerged)), {} }; } );
		return cata(alg_helper<Collection>(m), lfw(tree));
	};

	//----------------------------

	//C++ code generator:
	
	int tc = 0;
	auto VariableCollector = alg_helper<Set>( matcher( Tags::Symbol() | [](auto&& sub){ return Set( { (std::string)sub.ann() } ); },
		                                               Tags::Lambda() | [](auto&& sub){ return subtract_names(std::move(sub[1]), { *sub[0].begin() } ); },
		                                               Tags::App()    | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                                               Tags::Map()    | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                                               Tags::Zip()    | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                                               Tags::Rnz()    | [&](auto&& sub){ auto tmp = merge_names(sub.tree.chs); tmp.insert( "t" + std::to_string(tc++) + std::to_string(sub.ann().level)); return tmp; } ) );

	
	auto CppMatcher = matcher( Tags::Symbol() | [](auto&& sub){ return (std::string)sub.ann(); },
		                       Tags::Lambda() | [&](auto&& sub)
	                                            {
		                                           std::string res = "[&](auto res, auto " + sub[0].second;
		                                           if( unfix(sub[1].first).is_branch( Tags::Lambda() ) )
												   {
													   return res + ", auto " + (std::string)unfix(sub[1].first)[0].ann + remove_upto_closing_paren(sub[1].second) + "";
												   }
												   else{ return res + ")\n\t{\n\t   " + indent(sub[1].second) + ";\n\t}"; }
	                                            },
							   Tags::App()    | [](auto&& sub)
												{
													//return sub[0].second + "(" + sub[1].second + ")";
													if( unfix(sub[0].first).is_branch( Tags::App() ) )
												    {
														auto fn = sub[0].second.replace(sub[0].second.find("("), 1, "(res, ");
													    return fn.replace(sub[0].second.find(")"), 1, ", " + sub[1].second + ")");
												    }
													else{ return sub[0].second + "(" + sub[1].second + ")"; }
												},
							   Tags::Map()    | [](auto&& sub){ return std::string("map") /*+ std::to_string(sub.ann().level)*/ + "(res, " + sub[0].second + ", " + sub[1].second + ")"; },
							   Tags::Zip()    | [](auto&& sub){ return std::string("zip") /*+ std::to_string(sub.ann().level)*/ + "(res, " + sub[0].second + ", " + sub[1].second + ", " + sub[2].second + ")"; },
	                           Tags::Rnz()    | [&](auto&& sub){ return std::string("rnz") /*+ std::to_string(sub.ann().level)*/ + "(res, " + "t" + std::to_string(tc++) + std::to_string(sub.ann().level) + ", " + sub[0].second + ", " + sub[1].second + ", " + sub[2].second + ", " + sub[3].second + ")"; } );
	auto cppprint = [&](auto&& t)
	{ 
		tc = 0;
		std::stringstream ss;
		auto argnames = subtract_names(cata(VariableCollector, t), {"add", "mul", "lift"});
		tc = 0;
		ss << "template<";
		for(int i=0; i<(int)argnames.size(); ++i)
		{
			ss << "typename T" << i << ", ";
		}
		ss << "typename T" << (int)argnames.size() << ">\n";

		ss << "void kernel(T0&& res, ";

		int c = 1;
		auto it = argnames.begin();
		auto it2 = --argnames.end();
		for( ;it != it2; ++it)
		{
			ss << "T" << c << "&& " << *it << ", ";
			c += 1;
		}
		ss << "T" << c << "&& " << *it2 << ")\n{\n";

		ss << "   " << remove_tabs( indent( para(alg_helper<std::string>( CppMatcher ), t) ) ) + ";\n}\n";
		return ss.str();
	};

	//--------------------------------------

	AST a0;//, a1, a2a, a2b, a3;
	PatternTree rnzRaiseP, rnzRaiseR1, rnzRaiseR2, rnzLowerP, rnzLowerR1, rnzLowerR2, mapSubdivP, mapSubdivR, rnzSubdivP, rnzSubdivR, swapMapsP, swapMapsR, deliftP, deliftR;
	PatternTree betaP, betaR, etaP, etaR, eta2aP, eta2aR, eta2bP, eta2bR;
	PatternTree s1, s2, s3, s4, s5, s6, s7;

	std::set<std::string> names;
	for(char c = 'a'; c <= 'z'; ++c){ names.insert(std::string{c}); }
	for(char c = 'A'; c <= 'Z'; ++c){ names.insert(std::string{c}); }

	auto unused_names = [=](std::set<std::string> const& used_names)
	{
		std::set<std::string> res;
		std::set_difference( names.cbegin(), names.cend(), used_names.cbegin(), used_names.cend(), std::inserter(res, res.begin()));
		return res;
	};

	{
		using namespace ast;
		//a0 = App( Lambda("x"_sym, Map( Lambda("z"_sym, "z"_sym), "x"_sym)), "y"_sym );
		//a1 = App( Lambda( "x"_sym, Symbol("x*x") ), Symbol("y") );
		//a2a = Map( Lambda( "a"_sym, Rnz( Symbol("(+)"), Symbol("(*)"), Symbol("a"), Symbol("V") ) ), Symbol("A") );
		//a2b = Map( Lambda( "a"_sym, Rnz( Symbol("(+)"), Symbol("(*)"), Symbol("V"), Symbol("a") ) ), Symbol("A") );

		//a0 = Map( Lambda( "a"_sym, Map( Lambda( Symbol("b"), Rnz( "(+)"_sym, "(*)"_sym, Symbol("a"), Symbol("b") ) ), Symbol("B"))), Symbol("A") );
		//a0 = Map( Lambda( Sym("A", 0), Sym("t", 0) ), Sym("A", 1) );

		a0 = Map( Lambda( Sym("A", 1), Map( Lambda( Sym("B", 1), Rnz( Sym("add", 0), Sym("mul", 0), Sym("A", 1), Sym("B", 1) ) ), Sym("B", 2) ) ), Sym("A", 2) );
	}

	{
		using namespace patterns;
		s1 = Star("1");
		s2 = Star("2");
		s3 = Star("3");
		s4 = Star("4");
		s5 = Star("5");
		s6 = Star("6");
		s7 = Star("7");

		rnzRaiseP = Map( Lambda(s2, Rnz(s3, s4, s5, s6)), s1 );
		rnzRaiseR1 = Rnz( App( Symbol("lift"), s3), Lambda(s2, Lambda( "_1"_sym, Map( Lambda("_2"_sym, App( App(s4, "_2"_sym), "_1"_sym)), s2))), s1, s6);
		rnzRaiseR2 = Rnz( App( Symbol("lift"), s3), Lambda("_3"_sym, Lambda( s2, Map( Lambda("_4"_sym, App( App(s4, "_3"_sym), "_4"_sym)), s2))), s5, s1);

		rnzLowerP = Rnz(s1, Lambda(s2, Lambda(s3, Map(s4, s5))), s6, s7);
		rnzLowerR1 = Map( Lambda(s2, Rnz(App("delift"_sym, s1), Lambda("_1"_sym, Lambda(s3,       App(s4, "_1"_sym))), s2, s7 )), s6);//Rnz( App( Symbol("lift"), s3), Lambda(s2, Lambda( "_1"_sym, Map( Lambda("_2"_sym, App( App(s4, "_2"_sym), "_1"_sym)), s2))), s1, s6);
		rnzLowerR2 = Map( Lambda(s3, Rnz(App("delift"_sym, s1), Lambda(s2,       Lambda("_2"_sym, App(s4, "_2"_sym))), s6, s3 )), s7);//Rnz( App( Symbol("lift"), s3), Lambda("_3"_sym, Lambda( s2, Map( Lambda("_4"_sym, App( App(s4, "_3"_sym), "_4"_sym)), s2))), s5, s1);

		mapSubdivP = Map( s1, s2 );
		mapSubdivR = Map( Lambda( "_1"_sym, Map(s1, "_1"_sym)), s2 );

		swapMapsP = Map( Lambda(s1, Map(Lambda(s2, s3), s4)), s5);
		swapMapsR = Map( Lambda(s2, Map(Lambda(s1, s3), s5)), s4);

		deliftP = App("delift"_sym, App("lift"_sym, s1));
		deliftR = s1;

		rnzSubdivP = Rnz( s1, s2, s3, s4 );
		rnzSubdivR = Rnz( s1, Lambda( "_1"_sym, Lambda( "_2"_sym, Rnz(s1, s2, "_1"_sym, "_2"_sym) ) ), s3, s4 );

		betaP = App(Lambda(s2, s3), s1);
		betaR = s3;

		etaP = Lambda(s1, App(s2, s3));
		etaR = s2;

		eta2aP = Lambda(s1, Lambda(s2, App(s3, s4)));
		eta2aR = Lambda("_1"_sym, s3);

		eta2bP = Lambda(s2, App(App(s3, s4), s1));
		eta2bR = App(s3, "_1"_sym);
	}

	auto ASTNamesmatcher = matcher( Tags::Symbol() | [](auto&& sub){ return std::set<std::string>({sub.ann().data}); },
							        Tags::Lambda() | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                            Tags::App()    | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                            Tags::Map()    | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                            Tags::Zip()    | [](auto&& sub){ return merge_names(sub.tree.chs); },
		                            Tags::Rnz()    | [](auto&& sub){ return merge_names(sub.tree.chs); } );

	/*auto names_collector = alg_helper<std::set<std::string>>( ASTNamesmatcher );

	auto gen_new_names = [&](auto&& tree, auto&& m)
	{
		auto ns = unused_names( cata(names_collector, tree) );
		auto n1 = *( --ns.end() );
		auto n2 = *( ----ns.end() );
		auto t1 = replaceAll(patterns::Symbol("_1"), patterns::Symbol(n1), tree);
		auto t2 = replaceAll(patterns::Symbol("_2"), patterns::Symbol(n2), t1);
		return t2;
	};*/

	auto substid = [](auto const& tree, auto const& m){ return m[tree.ann().data]; };

	//substitution transform:
	//look up s2's symbol in match, create a pattern symbol from it, seek it, and replace it with the symbol created from looking up s1's matched symbol
	//auto subst = [&](auto&& tree, Match<AST> const& m){ return replaceAll(patterns::Symbol(m[s2.ann.data].ann), patterns::Symbol(m[s1.ann.data].ann), m[tree.ann().data]); };
	//Modified to only replace symbols with the same rank (level) (this is a hack)
	auto subst = [&](auto&& tree, Match<AST> const& m)
	{
		auto subst_constr = patternfamily(s4, replacer(patterns::Symbol(m[s1.ann.data].ann), substid, constraint([a = m[s2.ann.data].ann](auto&& x){ return x.ann.data == a.data && x.ann.level == a.level; }, s4)));
		//return replaceAll(patterns::Symbol(m[s2.ann.data].ann), patterns::Symbol(m[s1.ann.data].ann), m[tree.ann().data]);
		return replaceAllOfPattern(m[tree.ann().data], subst_constr, leftid);
	};

	auto pbeta = patternfamily(betaP, replacer(betaR, subst, constraint([](auto&& x, auto&& y){ return true; }, s1, s2)));
	auto betareduce = [&](auto&& t){ return fill_hof_rank(replaceAllOfPatterns(t, leftid, pbeta)); };

	auto peta = patternfamily(etaP, replacer(etaR, substid, constraint([](auto&& x, auto&& y){ return x.ann.data == y.ann.data; }, s1, s3)));

	auto eta2ab_final = [&](auto&& tree, Match<AST> const& m)
	{
		auto x1 = m[s1.ann.data];
		auto x2 = m[s2.ann.data];
		auto x4 = m[s4.ann.data];
		int b = (x1.ann.data == x4.ann.data) ? 2 : ((x2.ann.data == x4.ann.data) ? 1 : 0);
		auto c = coalg<TreeNode, ASTBranchList, NodeData>( [&](auto&& t)
		{
			if( t.is_branch( Tags::Symbol() ) && t.ann.data == "_1")
			{
				if     (b == 1){ return unfix(x1); }
				else if(b == 2){ return unfix(x2); }
				else { std::cout << "Invalid case in eta2a_final\n"; return unfix(t); }
			}
			return unfix(t);
		} );
		return ana(c, lfw(tree));
	};

	/*auto ceta2 = [](auto&& a1, auto&& a2, auto&& b1, auto&& b2){ return (a1.ann.data == b1.ann.data && a2.ann.data == b2.ann.data) ||
		                                                                (a1.ann.data == b2.ann.data && a2.ann.data == b1.ann.data); };
	auto peta2 = patternfamily(eta2P, replacer(eta2R, substid, constraint(ceta2, s1, s2, s4, s5)));*/
	auto peta2a = pattern(eta2aP, eta2aR, substid);
	auto peta2b = pattern(eta2bP, eta2bR, substid);
	auto etareduce = [&](auto&& t){ return replaceAllOfPatternsDown(replaceAllOfPatternsDown(t, leftid, peta), eta2ab_final, peta2a, peta2b); };

	/*auto sdmap_update_levels = [&](auto&& tree, Match<AST> const& m)
	{
		auto ann = m[s2.ann.data].ann;//ann of variable to be updated
		return replaceAll(patterns::Symbol("_1"), patterns::Symbol(ann), lfw(tree));
	};

	auto sdrnz_update_levels = [&](auto&& tree, Match<AST> const& m)
	{
		auto ann1 = m[s3.ann.data].ann;//ann of variable to be updated
		auto ann2 = m[s4.ann.data].ann;//ann of variable to be updated
		auto tmp1 = replaceAll(patterns::Symbol("_1"), patterns::Symbol(ann1), lfw(tree));
		auto tmp2 = replaceAll(patterns::Symbol("_2"), patterns::Symbol(ann2), tmp1);
		return tmp2;
	};*/

	auto sdmap_update_levels_full = [&](auto&& tree, Match<AST> const& m)
	{
		auto ann = m[s2.ann.data].ann;
		auto c = coalg<TreeNode, ASTBranchList, NodeData>( [&](auto&& t)
		{
			if( t.is_branch( Tags::Symbol() ) )
			{
				if(t.ann.data == ann.data && t.ann.level >= ann.level)
				{
					return unfix(ast::Sym(ann.data, t.ann.level+1));
				}
				else if(t.ann.data == "_1")
				{
					return unfix(ast::Sym(ann.data, ann.level));
				}
			}
			return unfix(t);
		} );
		return ana(c, lfw(tree));
	};

	auto sdrnz_update_levels_full = [&](auto&& tree, Match<AST> const& m)
	{
		auto ann1 = m[s3.ann.data].ann;
		auto ann2 = m[s4.ann.data].ann;
		auto c = coalg<TreeNode, ASTBranchList, NodeData>( [&](auto&& t)
		{
			if( t.is_branch( Tags::Symbol() ) )
			{
				if( t.ann.data == ann1.data && t.ann.level >= ann1.level)
				{
					return unfix(ast::Sym(ann1.data, t.ann.level+1));
				}
				else if( t.ann.data == ann2.data && t.ann.level >= ann2.level)
				{
					return unfix(ast::Sym(ann2.data, t.ann.level+1));
				}
				else if( t.ann.data == "_1" )
				{
					return unfix(ast::Sym(ann1.data, ann1.level));
				}
				else if( t.ann.data == "_2" )
				{
					return unfix(ast::Sym(ann2.data, ann2.level));
				}
			}
			return unfix(t);
		} );
		return ana(c, lfw(tree));
	};
	
	auto raisernz_update = [&](auto&& tree, Match<AST> const& m)
	{
		auto annA  = m[s1.ann.data].ann;
		auto annV1 = m[s6.ann.data].ann;
		auto annV2 = m[s5.ann.data].ann;
		auto c = coalg<TreeNode, ASTBranchList, NodeData>( [&](auto&& t)
		{
			if( t.is_branch( Tags::Symbol() ) )
			{
				if     ( t.ann.data == "_1" ){ return unfix(ast::Sym(annV1.data, annV1.level-1)); }
				else if( t.ann.data == "_2" ){ return unfix(ast::Sym(annA.data,  annA.level-2)); }
				else if( t.ann.data == "_3" ){ return unfix(ast::Sym(annV2.data, annV2.level-1)); }
				else if( t.ann.data == "_4" ){ return unfix(ast::Sym(annA.data,  annA.level-2)); }
			}
			return unfix(t);
		} );
		return ana(c, lfw(tree));
	};

	auto lowerrnz_update = [&](auto&& tree, Match<AST> const& m)
	{
		auto annV1 = m[s2.ann.data].ann;
		auto annV2 = m[s3.ann.data].ann;
		auto c = coalg<TreeNode, ASTBranchList, NodeData>( [&](auto&& t)
		{
			if( t.is_branch( Tags::Symbol() ) )
			{
				if     ( t.ann.data == "_1" ){ return unfix(ast::Sym(annV1.data, annV1.level-1)); }
				else if( t.ann.data == "_2" ){ return unfix(ast::Sym(annV2.data, annV2.level-1)); }
			}
			return unfix(t);
		} );
		return ana(c, lfw(tree));
	};
	
	auto prnzraise = patternfamily(rnzRaiseP, replacer(rnzRaiseR1, substid, constraint([](auto&& x, auto&& y){ return x.ann.data == y.ann.data; }, s2, s5)),
		                                      replacer(rnzRaiseR2, substid, constraint([](auto&& x, auto&& y){ return x.ann.data == y.ann.data; }, s2, s6)));

	auto prnzlower = patternfamily(rnzLowerP, replacer(rnzLowerR1, substid, constraint([](auto&& x, auto&& y){ return x.ann.data == y.ann.data; }, s2, s5)),
		                                      replacer(rnzLowerR2, substid, constraint([](auto&& x, auto&& y){ return x.ann.data == y.ann.data; }, s3, s5)));
	
	auto rnzraise_lowest  = [&](auto&& t){ return betareduce(replaceOneOfPattern    (t, prnzraise, raisernz_update, leftid)); };
	auto rnzraise_highest = [&](auto&& t){ return betareduce(replaceOneOfPatternDown(t, prnzraise, raisernz_update, leftid)); };

	auto psdmap    = pattern(mapSubdivP, mapSubdivR, substid);
	auto psdrnz    = pattern(rnzSubdivP, rnzSubdivR, substid);
	auto pswapMaps = pattern(swapMapsP,  swapMapsR,  substid);
	auto pdelift   = pattern(deliftP,    deliftR,    substid);
	auto delift = [&](auto&& t){ return replaceAllOfPatterns(t, leftid, pdelift); };

	auto sdmap_lowest  = [&](auto&& t){ return betareduce(replaceOneOfPattern    (t, psdmap, leftid, sdmap_update_levels_full)); };
	auto sdmap_highest = [&](auto&& t){ return betareduce(replaceOneOfPatternDown(t, psdmap, leftid, sdmap_update_levels_full)); };
	auto sdrnz_lowest  = [&](auto&& t){ return betareduce(replaceOneOfPattern    (t, psdrnz, leftid, sdrnz_update_levels_full)); };
	auto sdrnz_highest = [&](auto&& t){ return betareduce(replaceOneOfPatternDown(t, psdrnz, leftid, sdrnz_update_levels_full)); };

	std::cout << "Original:\n" << cppprint(fill_hof_rank(a0)) << "\n\n";

	//std::cout << "Subdividing the lowest map:\n" << cppprint(sdmap_lowest(a0)) << "\n\n";
	//std::cout << "Subdividing the highest map:\n" << cppprint(sdmap_highest(a0)) << "\n\n";

	/*auto tmp = sdrnz_lowest(a0);
	std::cout << "Subdividing the rnz:\n" << cppprint(tmp) << "\n\n";

	auto tmp2 = rnzraise_highest(tmp);
	std::cout << "Raising the upper rnz:\n" << cppprint(tmp2) << "\n\n";

	auto tmp3 = rnzraise_highest(tmp2);
	std::cout << "Raising the upper rnz:\n" << cppprint(tmp3) << "\n\n";

	std::cout << collect_dependency_string(tmp3).merged << "\n";*/

	/*auto t1 = betareduce(replaceNthHoFPatternDown(a0, 0, psdmap, leftid, sdmap_update_levels_full));
	std::cout << "sd 0:\n" << cppprint(t1) << "\n\n";

	auto t2 = betareduce(replaceNthHoFPatternDown(a0, 1, psdmap, leftid, sdmap_update_levels_full));
	std::cout << "sd 1:\n" << cppprint(t2) << "\n\n";

	auto t3 = betareduce(replaceNthHoFPatternDown(a0, 1, prnzraise, raisernz_update, leftid));
	std::cout << "rnzraise 1:\n" << cppprint(t3) << "\n\n";

	return 0;*/
	//bahh
	{
		//std::vector<std::string> HoF{ "mA", "mA", "mB", "mB", "rAB", "rAB" };

		std::vector<std::string> HoF{ "mA", "mB", "rAB", "rAB", "rAB" };

		std::vector<int> flipA, flipB, flipC;

		auto print_flip = [&](std::string const& name, auto const& v)
		{
			//std::cout << "//" << name << ":\n//";
			std::stringstream ss;
			for(auto e : v){ ss << "flip<" << e << ">( "; }
			//if(name != "res_"){ ss << "subdiv<1, b>("; }
			//if(name != "res_"){ ss << "subdiv<0, b>("; }
			if(name != "res_")
			{
				//6:
				//if     ( name[0] == 'A' ){ ss << "subdiv<0, b>( subdiv<1, b>("; }
				//else if( name[0] == 'B' ){ ss << "subdiv<0, b>( subdiv<1, b>("; }
				//5b:
				if     ( name[0] == 'A' ){ ss << "subdiv<1, b>( subdiv<1, b>("; }
				else if( name[0] == 'B' ){ ss << "subdiv<1, b>( subdiv<1, b>("; }
			}
			ss << name;
			//ss << ")";
			if(name != "res_"){ ss << ") )"; }
			//if(name != "res_"){ ss << ")"; }
			for(auto e : v){ ss << " )"; }
			ss << ";\n";
			return ss.str();
		};

		auto cppprint2 = [&](int count, auto&& t)
		{ 
			tc = 0;
			std::stringstream ss;
			auto argnames = subtract_names(cata(VariableCollector, t), {"add", "mul", "lift"});
			auto ntmp = std::count_if(argnames.begin(), argnames.end(), [](auto const& s){ return s[0] == 't'; });
			tc = 0;
			ss << "template<int b, ";
			for(int i=0; i<(int)argnames.size() - ntmp; ++i)
			{
				ss << "typename T" << i << ", ";
			}
			ss << "typename T" << (int)argnames.size() - ntmp << ">\n";

			ss << "auto kernel_lvl5(Int<" << count-1 << ">, T0&& res_";

			int c = 1;
			auto it = argnames.begin();
			auto it2 = --argnames.end();
			for( ;it != it2; ++it)
			{
				bool istmp = ((*it)[0]) == 't';
				if( istmp ){ continue; }
				ss << ", T" << c << "&& " << *it << (!istmp ? "_" : "");
				c += 1;
			}
			if( (*it2)[0] != 't' ){ ss << "T" << c << "&& " << *it2; }
			ss << ")\n{\n";
			ss << "   auto res = " << print_flip("res_", flipC);
			it2 = argnames.end();
			for(it = argnames.begin(); it != it2; ++it)
			{
				auto ch = (*it)[0];
				std::vector<int>* v = nullptr;
				if     (ch == 'A'){ v = &flipA; }
				else if(ch == 'B'){ v = &flipB; }

				if(v){ ss << "   auto " << *it << " = " << print_flip(*it + "_", *v); }

				if( ch == 't' )
				{
					ss << "   auto " << *it << " = " << "AllocateViewSimilarToButDropFrontDimensionsUpTo<" << (*it)[2] << ">(res);\n";
				}
			}
			
			ss << "   auto time0 = std::chrono::high_resolution_clock::now();\n";
			ss << "   " << remove_tabs( indent( para(alg_helper<std::string>( CppMatcher ), t) ) ) + ";\n";
			ss << "   auto time1 = std::chrono::high_resolution_clock::now();\n";

			it2 = argnames.end();
			for(it = argnames.begin(); it != it2; ++it)
			{
				if( (*it)[0] == 't' )
				{
					ss << "   Deallocate(" << *it << ");\n";
				}
			}

			ss << "   return ms(time0, time1);\n}\n";
			return ss.str();
		};

		auto hof_idx = [&](char c, int l)
		{
			int i=0;
			for(int k=0; k<l; ++k)
			{
				if     (HoF[k][0] == 'm' && HoF[k][1] == c){ i += 1; }
				else if(HoF[k][0] == 'r' && (HoF[k][1] == c || HoF[k][2] == c)){ i += 1; }
			}
			return i;
		};

		auto map_idx = [&](char c, int l)
		{
			int i=0;
			for(int k=0; k<l; ++k)
			{
				if(HoF[k][0] == 'm' /*&& HoF[k][1] == c*/){ i += 1; }
			}
			return i;
		};

		JohnsonTrotterState_ state(5);
		//AST tree = fill_hof_rank(a0);
		AST tree = fill_hof_rank(sdrnz_highest(sdrnz_lowest(a0)));
		//AST tree = fill_hof_rank( sdmap_highest( sdmap_lowest( sdrnz_lowest(a0) ) ) );

		std::ofstream file("generated_lvl5b.hpp");

		auto print_step = [&](std::ostream& os, int c)
		{
			os << "//permutation: " << c << "\n";
			os << "//" ;
			for (auto e : HoF){ os << e << " "; }
			os << "\n";

			//print_flip("A", flipA);
			//print_flip("B", flipB);
			//print_flip("C", flipC);
			
			os << "//";
			for (auto v : state.values_){ os << v << " "; }
			os << "\n";

			os << cppprint2(c, etareduce(etareduce(tree))) << "\n\n";
		};

		auto flipmap = [&]( char c, int i )
		{
			int j = hof_idx(c, i);
			if     ( c == 'A' ){ if(flipA.size() == 0 || flipA[0] != j){ flipA.insert(flipA.begin(), j); }else{ flipA.erase(flipA.begin()); } }
			else if( c == 'B' ){ if(flipB.size() == 0 || flipB[0] != j){ flipB.insert(flipB.begin(), j); }else{ flipB.erase(flipB.begin()); } }
			else if( c == 'C' ){ if(flipC.size() == 0 || flipC[0] != i){ flipC.insert(flipC.begin(), i); }else{ flipC.erase(flipC.begin()); } }
		};

		auto fliprnz = [&]( std::string const& r, std::string const& m, int i )
		{
			auto c = m[1];
			if     ( r[1] == c ){ flipmap(c, i-1); }
			else if( r[2] == c ){ flipmap(c, i-1); }
		};

		int count = 1;
		do
		{
			std::cout << "Permutation: " << count << "\n";
			print_step(file, count);
			auto i = ++state;
			if     ( HoF[i-1][0] == 'm' && HoF[i][0] == 'r' ){ tree = betareduce(replaceNthHoFPatternDown(tree, i-1, prnzraise, raisernz_update, leftid));                        fliprnz(HoF[i  ], HoF[i-1], i); }//azt kell flippelni, amelyik egyezik}
			else if( HoF[i-1][0] == 'r' && HoF[i][0] == 'm' ){ tree = fill_hof_rank(delift(betareduce(replaceNthHoFPatternDown(tree, i-1, prnzlower, lowerrnz_update, leftid)))); fliprnz(HoF[i-1], HoF[i  ], i); }//azt kell flippelni, amelyik egyezik}
			else if( HoF[i-1][0] == 'm' && HoF[i][0] == 'm' &&
				     HoF[i-1][1] != HoF[i][1] ){ tree = betareduce(replaceNthHoFPatternDown(tree, i-1, pswapMaps, leftid, leftid)); flipmap('C', /*i-1*/map_idx(HoF[i-1][1], i-1)); }
			std::swap( HoF[i-1], HoF[i] );
			file << "//swap at indices " << i-1 << " " << i << ":\n";
			count += 1;

			//if(count == 31){ break; }

		} while (!state.IsComplete());

		print_step(file, count);
	}



	//auto tmp4 = rnzraise_lowest(tmp3);
	//std::cout << "Raising the lower rnz:\n" << cppprint(tmp4) << "\n\n";

	//std::cout << "Initial tree: " << cata(ast_print, a0) << "\n";
	//std::cout << "Final   tree: " << cata(ast_print, r0) << "\n\n";

	/*auto r2b = replaceAllOfPatterns(a2b, gen_new_names, p);
	auto r3a  = replaceOneOfPattern(a3,  p, gen_new_names);
	auto r3b  = replaceOneOfPattern(r3a, p, gen_new_names);
	auto r3c  = replaceAllOfPattern(r3b, q, gen_new_names);*/

	

	//std::cout << "Pattern: " << cata(pattern_print, rnzRaiseP) << "\n";
	//std::cout << "Replacement1: " << cata(pattern_print, rnzRaiseR1) << "\n";
	//std::cout << "Replacement2: " << cata(pattern_print, rnzRaiseR2) << "\n\n";

	/*std::cout << "Initial tree1: " << cata(ast_print, a1) << "\n\n";

	std::cout << "Initial tree2: " << cata(ast_print, a2a) << "\n\n";
	std::cout << "Final tree2: " << cata(ast_print, r2a) << "\n\n";

	std::cout << "Initial tree3: " << cata(ast_print, a2b) << "\n\n";
	std::cout << "Final tree3: " << cata(ast_print, r2b) << "\n\n";

	std::cout << "Initial tree4: " << cata(ast_print, a3) << "\n";
	std::cout << "Final tree4: " << cata(ast_print, r3a) << "\n\n";
	std::cout << "Final tree4: " << cata(ast_print, r3b) << "\n\n";
	std::cout << "Final tree4: " << cata(ast_print, r3c) << "\n\n";*/

	/*auto rnz_raise_n = [&](auto&& t, int n)
	{
		std::stringstream res;
		auto u = t;
		for(int i=0; i<n; ++i)
		{
			u = rnzraise(u);
			res << i << " " << print(u) << "\n\n";
		}
		res << "\n";
		return res.str();
	};

	std::cout << "Matmul 3: " << print(a0) << "\n\n";

	auto a11 = sdmap(a0);
	std::cout << "Matmul 4a sd map: " << print(a11) << "\n\n";
	std::cout << rnz_raise_n(a11, 3);

	auto a12 = sdrnz(a0);
	std::cout << "Matmul 4b sd rnz: " << print(a12) << "\n\n";
	std::cout << rnz_raise_n(a12, 4);

	auto a13 = replaceAllOfPattern(sdrnz(a0), psdmap, gen_new_names);
	std::cout << "Matmul 6 sd rnz: " << print(a13) << "\n\n";
	std::cout << rnz_raise_n(a13, 12);*/

	/*auto a1 = rnzraise(a0);
	std::cout << "Matmul 2: " << print(a1) << "\n\n";

	auto a2 = rnzraise(a1);
	std::cout << "Matmul 3: " << print(a2) << "\n\n";*/

	//std::cout << "Matmul sd map: " << print( replaceAllOfPattern(a0, psdmap, gen_new_names) ) << "\n\n";
	//std::cout << "Matmul sd map: " << print(sdmap(a0)) << "\n\n";

	//std::cout << "Matmul sd rnz: " << print(sdrnz(a0)) << "\n\n";



	//std::cout << "Initial tree3: " << cata(ast_print, a4) << "\n";
	//std::cout << "Final tree2: " << cata(ast_print, b2) << "\n";
	
	return 0;
}