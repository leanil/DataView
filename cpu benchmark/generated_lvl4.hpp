#pragma once

//permutation: 1
//mA mB rAB rAB
//1 2 3 4
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<0>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = subdiv<1, b>(A3_);
   auto B3 = subdiv<1, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 2
//mA mB rAB rAB
//1 2 4 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<1>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = subdiv<1, b>(A3_);
   auto B3 = subdiv<1, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 3
//mA rAB mB rAB
//1 4 2 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<2>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = subdiv<1, b>(A3_);
   auto B3 = flip<0>( subdiv<1, b>(B3_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 4
//rAB mA mB rAB
//4 1 2 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<3>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( subdiv<1, b>(A3_) );
   auto B3 = flip<0>( subdiv<1, b>(B3_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 5
//rAB mA rAB mB
//4 1 3 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<4>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( subdiv<1, b>(A3_) );
   auto B3 = flip<1>( flip<0>( subdiv<1, b>(B3_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      map(res, [&](auto res, auto A1)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
         {
            map(res, mul(A), B1);
         }, A1, B2);
      }, A2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 6
//mA rAB rAB mB
//1 4 3 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<5>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<0>( subdiv<1, b>(A3_) ) );
   auto B3 = flip<1>( flip<0>( subdiv<1, b>(B3_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A2)
   {
      rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
         {
            map(res, mul(A), B1);
         }, A1, B2);
      }, A2, B3);
   }, A3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 7
//mA rAB rAB mB
//1 3 4 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<6>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<0>( subdiv<1, b>(A3_) ) );
   auto B3 = flip<1>( flip<0>( subdiv<1, b>(B3_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A2)
   {
      rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
         {
            map(res, mul(A), B1);
         }, A1, B2);
      }, A2, B3);
   }, A3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 8
//mA rAB mB rAB
//1 3 2 4
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<7>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<0>( subdiv<1, b>(A3_) ) );
   auto B3 = flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 9
//rAB mA mB rAB
//3 1 2 4
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<8>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) );
   auto B3 = flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 10
//rAB mA rAB mB
//3 1 4 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<9>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      map(res, [&](auto res, auto A1)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
         {
            map(res, mul(A), B1);
         }, A1, B2);
      }, A2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 11
//rAB rAB mA mB
//3 4 1 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<10>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
      {
         map(res, [&](auto res, auto A)
         {
            map(res, mul(A), B1);
         }, A1);
      }, A2, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 12
//rAB rAB mA mB
//4 3 1 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<11>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
      {
         map(res, [&](auto res, auto A)
         {
            map(res, mul(A), B1);
         }, A1);
      }, A2, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 13
//rAB rAB mB mA
//4 3 2 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<12>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
      {
         map(res, [&](auto res, auto B)
         {
            map(res, mul(B), A1);
         }, B1);
      }, A2, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 14
//rAB rAB mB mA
//3 4 2 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<13>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
      {
         map(res, [&](auto res, auto B)
         {
            map(res, mul(B), A1);
         }, B1);
      }, A2, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 15
//rAB mB rAB mA
//3 2 4 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<14>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      map(res, [&](auto res, auto B1)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
         {
            map(res, mul(B), A1);
         }, A2, B1);
      }, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 16
//rAB mB mA rAB
//3 2 1 4
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<15>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) );
   auto B3 = flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      map(res, [&](auto res, auto B1)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t00, add, mul, A1, B1);
         }, A2);
      }, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 17
//mB rAB mA rAB
//2 3 1 4
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<16>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) );
   auto B3 = flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B2)
   {
      rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t00, add, mul, A1, B1);
         }, A2);
      }, A3, B2);
   }, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 18
//mB rAB rAB mA
//2 3 4 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<17>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) );
   auto B3 = flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B2)
   {
      rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
         {
            map(res, mul(B), A1);
         }, A2, B1);
      }, A3, B2);
   }, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 19
//mB rAB rAB mA
//2 4 3 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<18>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) );
   auto B3 = flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B2)
   {
      rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
         {
            map(res, mul(B), A1);
         }, A2, B1);
      }, A3, B2);
   }, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 20
//rAB mB rAB mA
//4 2 3 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<19>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) );
   auto B3 = flip<0>( flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      map(res, [&](auto res, auto B1)
      {
         rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
         {
            map(res, mul(B), A1);
         }, A2, B1);
      }, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 21
//rAB mB mA rAB
//4 2 1 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<20>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) ) );
   auto B3 = flip<0>( flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t12, lift(lift(add)), [&](auto res, auto A2, auto B2)
   {
      map(res, [&](auto res, auto B1)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t00, add, mul, A1, B1);
         }, A2);
      }, B2);
   }, A3, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 22
//mB rAB mA rAB
//2 4 1 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<21>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) ) );
   auto B3 = flip<0>( flip<0>( flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B2)
   {
      rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t00, add, mul, A1, B1);
         }, A2);
      }, A3, B2);
   }, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 23
//mB mA rAB rAB
//2 1 4 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<22>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) ) ) );
   auto B3 = flip<0>( flip<0>( flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B2)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t10, add, [&](auto res, auto A1, auto B1)
         {
            rnz(res, t00, add, mul, A1, B1);
         }, A2, B2);
      }, A3);
   }, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 24
//mB mA rAB rAB
//2 1 3 4
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl4(Int<23>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto A3 = flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( flip<0>( flip<0>( subdiv<1, b>(A3_) ) ) ) ) ) ) ) );
   auto B3 = flip<0>( flip<0>( flip<0>( flip<1>( flip<1>( flip<1>( flip<1>( flip<0>( subdiv<1, b>(B3_) ) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B2)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t10, add, [&](auto res, auto A1, auto B1)
         {
            rnz(res, t00, add, mul, A1, B1);
         }, A2, B2);
      }, A3);
   }, B3);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}