#pragma once

//permutation: 1
//mA mB rAB
//1 2 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl3(Int<0>, T0&& res_, T1&& A2_, T2&& B2_)
{
   auto A2 = A2_;
   auto B2 = B2_;
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A1)
   {
      map(res, [&](auto res, auto B1)
      {
         rnz(res, t00, add, mul, A1, B1);
      }, B2);
   }, A2);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 2
//mA rAB mB
//1 3 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl3(Int<1>, T0&& res_, T1&& A2_, T2&& B2_)
{
   auto A2 = A2_;
   auto B2 = flip<0>( B2_ );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A1)
   {
      rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
      {
         map(res, mul(A), B1);
      }, A1, B2);
   }, A2);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 3
//rAB mA mB
//3 1 2
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl3(Int<2>, T0&& res_, T1&& A2_, T2&& B2_)
{
   auto A2 = flip<0>( A2_ );
   auto B2 = flip<0>( B2_ );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = res_;
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
   {
      map(res, [&](auto res, auto A)
      {
         map(res, mul(A), B1);
      }, A1);
   }, A2, B2);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 4
//rAB mB mA
//3 2 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl3(Int<3>, T0&& res_, T1&& A2_, T2&& B2_)
{
   auto A2 = flip<0>( A2_ );
   auto B2 = flip<0>( B2_ );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
   {
      map(res, [&](auto res, auto B)
      {
         map(res, mul(B), A1);
      }, B1);
   }, A2, B2);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 5
//mB rAB mA
//2 3 1
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl3(Int<4>, T0&& res_, T1&& A2_, T2&& B2_)
{
   auto A2 = flip<0>( A2_ );
   auto B2 = flip<0>( flip<0>( B2_ ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B1)
   {
      rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
      {
         map(res, mul(B), A1);
      }, A2, B1);
   }, B2);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 6
//mB mA rAB
//2 1 3
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl3(Int<5>, T0&& res_, T1&& A2_, T2&& B2_)
{
   auto A2 = flip<0>( flip<0>( A2_ ) );
   auto B2 = flip<0>( flip<0>( B2_ ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res_);
   auto res = flip<0>( res_ );
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B1)
   {
      map(res, [&](auto res, auto A1)
      {
         rnz(res, t00, add, mul, A1, B1);
      }, A2);
   }, B2);
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}