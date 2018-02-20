#include "benchmark_util.h"
#include "hof.h"
#include "View.h"
#include <chrono>
#include <utility>
#include <vector>

using namespace hof;

template<typename F>
auto lift(F const& f) {
    return [=](auto res, auto A, auto B) {
        zip(res, f, A, B);
    };
}

namespace t1 {
    template<typename T0, typename T1, typename T2, typename T3>
    void kernel(T0&& res, T1&& A2, T2&& B2, T3&& t00)
    {
        map(res, [&](auto res, auto A1)
        {
            map(res, [&](auto res, auto B1)
            {
                rnz(res, t00, add, mul, A1, B1);
            }, B2);
        }, A2);
    }

    template<int n, typename T>
    auto test(std::vector<T> const& A, std::vector<T> const& B)
    {
        std::vector<T> C(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        View<T*, T, EmptyList> tmp(new T);
        auto t0 = std::chrono::high_resolution_clock::now();
        kernel(vC, vA, vB, tmp);
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::make_pair(C, ms(t0, t1));;
    }
}

namespace t2 {
    // Subdividing the rnz :
    template<typename T0, typename T1, typename T2, typename T3, typename T4>
    void kernel(T0&& res, T1&& A3, T2&& B3, T3&& t00, T4&& t10)
    {
        map(res, [&](auto res, auto A2)
        {
            map(res, [&](auto res, auto B2)
            {
                rnz(res, t10, add, [&](auto res, auto A1, auto B1)
                {
                    rnz(res, t00, add, mul, A1, B1);
                }, A2, B2);
            }, B3);
        }, A3);
    }

    template<int n, int b, typename T>
    auto test(std::vector<T> const& A, std::vector<T> const& B)
    {
        std::vector<T> C(n*n);
        View<T const*, T, subdiv_t<1, b, to_list_t<P<n, n>, P<n, 1>>>> vA(A.data());
        View<T const*, T, subdiv_t<1, b, to_list_t<P<n, 1>, P<n, n>>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        View<T*, T, EmptyList> tmp1(new T), tmp2(new T);
        auto t0 = std::chrono::high_resolution_clock::now();
        kernel(vC, vA, vB, tmp1, tmp2);
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::make_pair(C, ms(t0, t1));;
    }
}

namespace t3 {
    // Raising the upper rnz :
    template<typename T0, typename T1, typename T2, typename T3, typename T4>
    void kernel(T0&& res, T1&& A3, T2&& B3, T3&& t00, T4&& t11)
    {
        map(res, [&](auto res, auto A2)
        {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
                map(res, [&](auto res, auto B1)
                {
                    rnz(res, t00, add, mul, A1, B1);
                }, B2);
            }, A2, B3);
        }, A3);
    }

    template<int n, int b, typename T>
    auto test(std::vector<T> const& A, std::vector<T> const& B)
    {
        std::vector<T> C(n*n), tmp(n);
        View<T const*, T, subdiv_t<1, b, to_list_t<P<n, n>, P<n, 1>>>> vA(A.data());
        View<T const*, T, flip_t<0, subdiv_t<1, b, to_list_t<P<n, 1>, P<n, n>>>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        View<T*, T, EmptyList> tmp1(new T);
        View<T*, T, to_list_t<P<n, 1>>> tmp2(tmp.data());
        auto t0 = std::chrono::high_resolution_clock::now();
        kernel(vC, vA, vB, tmp1, tmp2);
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::make_pair(C, ms(t0, t1));;
    }
}

namespace t4 {
    // Raising the upper rnz :
    template<int b, typename T0, typename T1, typename T2, typename T3, typename T4>
    void kernel(T0&& _res, T1&& _A3, T2&& _B3, T3&& t00, T4&& t12)
    {
        auto A3 = flip<0>(subdiv<1, b>(_A3));
        auto B3 = flip<0>(subdiv<1, b>(_B3));
		auto res = _res;//flip<0>(_res);
        rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
        {
            map(res, [&](auto res, auto A1)
            {
                map(res, [&](auto res, auto B1)
                {
                    rnz(res, t00, add, mul, A1, B1);
                }, B2);
            }, A2);
        }, A3, B3);
    }

    template<int n, int b, typename T>
    auto test(std::vector<T> const& A, std::vector<T> const& B)
    {
        std::vector<T> C(n*n), tmp(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        View<T*, T, EmptyList> tmp1(new T);
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> tmp2(tmp.data());
        auto t0 = std::chrono::high_resolution_clock::now();
        kernel<b>(vC, vA, vB, tmp1, tmp2);
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::make_pair(C, ms(t0, t1));;
    }
}


namespace t5 {
	template<int b, typename T0, typename T1, typename T2>
    void kernel(T0&& _res, T1&& _A3, T2&& _B3)
	{
	   auto A3 =         subdiv<1, b>(_A3) ;
       auto B3 = flip<0>(subdiv<1, b>(_B3));
	   auto res = _res;//flip<0>(_res);
	   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(_res);//NewView(recalcstrides( keepback<1>(_res)));//NewView(recalcstrides( dropfront<1>(_res) ) );
	   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(_res);//NewView(recalcstrides( keepback<0>(_res)));//NewView(recalcstrides( dropfront<2>(_res) ) );
	   map(res, [&](auto res, auto A2)
	   {
		  rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
		  {
			 map(res, [&](auto res, auto B1)
			 {
				rnz(res, t00, add, mul, A1, B1);
			 }, B2);
		  }, A2, B3);
	   }, A3);
	}

    template<int n, int b, typename T>
    auto test(std::vector<T> const& A, std::vector<T> const& B)
    {
        std::vector<T> C(n*n);//, tmp(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        //View<T*, T, EmptyList> tmp1(new T);
		//auto tmp2 = dropfront<1>( View<T*, T, to_list_t<P<n, n>, P<n, 1>>>{ tmp.data() } );
        //View<T*, T, to_list_t<P<n, 1>>> tmp2(tmp.data());
        auto t0 = std::chrono::high_resolution_clock::now();
        kernel<b>(vC, vA, vB);
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::make_pair(C, ms(t0, t1));;
    }
}




namespace t6 {
#include "generated_lvl3.hpp"
#include "generated_lvl4.hpp"
#include "generated_lvl5b.hpp"
#include "generated_lvl6.hpp"

    /*template<int n, int b, typename T>
    auto test(std::vector<T> const& A, std::vector<T> const& B)
    {
        std::vector<T> C(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        auto dt = kernel<b>(Int<24>(), vC, vA, vB);
        return std::make_pair(C, dt);
    }*/
}

struct Result
{
	int index;
	double dt;
	bool passed;
};

template<int n, int b, typename T>
auto testone_lvl3(std::vector<T> const& A, std::vector<T> const& B, std::vector<T> const& Cknown)
{
	return [=](auto I)
	{
		std::vector<T> C(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        auto dt = t6::kernel_lvl3<b>(I, vC, vA, vB);
		auto b = is_same(C, Cknown);
		std::cout << "Step: " << (int)I << " " << dt << " ms" << "(" << (b ? '+' : '-') << ")\n";
		return Result{(int)I, dt, is_same(C, Cknown)};
	};
}

template<int n, int b, typename T>
auto testone_lvl4(std::vector<T> const& A, std::vector<T> const& B, std::vector<T> const& Cknown)
{
	return [=](auto I)
	{
		std::vector<T> C(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        auto dt = t6::kernel_lvl4<b>(I, vC, vA, vB);
		auto b = is_same(C, Cknown);
		std::cout << "Step: " << (int)I << " " << dt << " ms" << "(" << (b ? '+' : '-') << ")\n";
		return Result{(int)I, dt, is_same(C, Cknown)};
	};
}

template<int n, int b, typename T>
auto testone_lvl5(std::vector<T> const& A, std::vector<T> const& B, std::vector<T> const& Cknown)
{
	return [=](auto I)
	{
		std::vector<T> C(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        //auto dt = t6::kernel_lvl5<b>(I, subdiv<0, b>( subdiv<1, b>(vC) ), vA, vB);
		auto dt = t6::kernel_lvl5<b>(I, vC, vA, vB);
		auto b = is_same(C, Cknown);
		std::cout << "Step: " << (int)I << " " << dt << " ms" << "(" << (b ? '+' : '-') << ")\n";
		return Result{(int)I, dt, b};
	};
}

template<int n, int b, typename T>
auto testone_lvl6(std::vector<T> const& A, std::vector<T> const& B, std::vector<T> const& Cknown)
{
	return [=](auto I)
	{
		std::vector<T> C(n*n);
        View<T const*, T, to_list_t<P<n, n>, P<n, 1>>> vA(A.data());
        View<T const*, T, to_list_t<P<n, 1>, P<n, n>>> vB(B.data());
        View<T*, T, to_list_t<P<n, n>, P<n, 1>>> vC(C.data());
        auto dt = t6::kernel_lvl6<b>(I, subdiv<0, b>( subdiv<1, b>(vC) ), vA, vB);
		auto b = is_same(C, Cknown);
		std::cout << "Step: " << (int)I << " " << dt << " ms" << "(" << (b ? '+' : '-') << ")\n";
		return Result{(int)I, dt, b};
	};
}

template<typename F, typename Z, typename M>
auto fold_imap(Int<0> I, F&& f, Z&& z, M&& m)
{
	return f(z, m(I));
}

template<int i, typename F, typename Z, typename M>
auto fold_imap(Int<i> I, F&& f, Z&& z, M&& m)
{
	return fold_imap(Int<I-1>(), f, f(z, m(I)), m);
}