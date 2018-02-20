//permutation: 1
//mA mB rAB rAB rAB 
//1 2 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<0>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 2
//mA mB rAB rAB rAB 
//1 2 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<1>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 3
//mA mB rAB rAB rAB 
//1 2 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<2>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 4
//mA rAB mB rAB rAB 
//1 5 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<3>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 5
//rAB mA mB rAB rAB 
//5 1 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<4>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 6
//rAB mA mB rAB rAB 
//5 1 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<5>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 7
//mA rAB mB rAB rAB 
//1 5 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<6>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 8
//mA mB rAB rAB rAB 
//1 2 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<7>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 9
//mA mB rAB rAB rAB 
//1 2 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<8>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 10
//mA mB rAB rAB rAB 
//1 2 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<9>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 11
//mA rAB mB rAB rAB 
//1 4 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<10>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 12
//mA rAB mB rAB rAB 
//1 4 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<11>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 13
//mA rAB rAB mB rAB 
//1 4 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<12>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 14
//mA rAB rAB mB rAB 
//1 5 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<13>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 15
//rAB mA rAB mB rAB 
//5 1 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<14>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 16
//rAB rAB mA mB rAB 
//5 4 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<15>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 17
//rAB rAB mA mB rAB 
//4 5 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<16>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 18
//rAB mA rAB mB rAB 
//4 1 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<17>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 19
//rAB mA mB rAB rAB 
//4 1 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<18>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 20
//rAB mA mB rAB rAB 
//4 1 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<19>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 21
//rAB mA rAB mB rAB 
//4 1 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<20>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 22
//rAB mA rAB rAB mB 
//4 1 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<21>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 23
//rAB mA rAB rAB mB 
//4 1 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<22>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 24
//rAB rAB mA rAB mB 
//4 5 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<23>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 25
//rAB rAB mA rAB mB 
//5 4 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<24>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 26
//rAB mA rAB rAB mB 
//5 1 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<25>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 27
//mA rAB rAB rAB mB 
//1 5 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<26>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
            {
               map(res, mul(A), B1);
            }, A1, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 28
//mA rAB rAB rAB mB 
//1 4 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<27>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
            {
               map(res, mul(A), B1);
            }, A1, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 29
//mA rAB rAB rAB mB 
//1 4 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<28>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
            {
               map(res, mul(A), B1);
            }, A1, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 30
//mA rAB rAB mB rAB 
//1 4 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<29>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 31
//mA rAB rAB mB rAB 
//1 3 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<30>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 32
//mA rAB rAB rAB mB 
//1 3 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<31>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
            {
               map(res, mul(A), B1);
            }, A1, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 33
//mA rAB rAB rAB mB 
//1 3 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<32>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
            {
               map(res, mul(A), B1);
            }, A1, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 34
//mA rAB rAB rAB mB 
//1 5 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<33>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
            {
               map(res, mul(A), B1);
            }, A1, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 35
//rAB mA rAB rAB mB 
//5 1 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<34>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 36
//rAB mA rAB mB rAB 
//5 1 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<35>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 37
//mA rAB rAB mB rAB 
//1 5 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<36>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 38
//mA rAB rAB mB rAB 
//1 3 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<37>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 39
//mA rAB mB rAB rAB 
//1 3 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<38>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 40
//mA rAB mB rAB rAB 
//1 3 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<39>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 41
//rAB mA mB rAB rAB 
//3 1 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<40>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 42
//rAB mA mB rAB rAB 
//3 1 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<41>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 43
//rAB mA rAB mB rAB 
//3 1 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<42>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 44
//rAB rAB mA mB rAB 
//3 5 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<43>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 45
//rAB rAB mA mB rAB 
//5 3 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<44>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 46
//rAB rAB mA rAB mB 
//5 3 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<45>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 47
//rAB rAB mA rAB mB 
//3 5 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<46>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 48
//rAB mA rAB rAB mB 
//3 1 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<47>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 49
//rAB mA rAB rAB mB 
//3 1 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<48>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 50
//rAB mA rAB mB rAB 
//3 1 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<49>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 51
//rAB rAB mA mB rAB 
//3 4 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<50>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 52
//rAB rAB mA rAB mB 
//3 4 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<51>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 53
//rAB rAB rAB mA mB 
//3 4 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<52>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 54
//rAB rAB rAB mA mB 
//3 5 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<53>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 55
//rAB rAB rAB mA mB 
//5 3 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<54>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 56
//rAB rAB rAB mA mB 
//5 4 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<55>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 57
//rAB rAB rAB mA mB 
//4 5 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<56>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 58
//rAB rAB rAB mA mB 
//4 3 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<57>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 59
//rAB rAB mA rAB mB 
//4 3 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<58>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 60
//rAB rAB mA mB rAB 
//4 3 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<59>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 61
//rAB rAB mB mA rAB 
//4 3 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<60>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 62
//rAB rAB mB rAB mA 
//4 3 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<61>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 63
//rAB rAB rAB mB mA 
//4 3 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<62>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 64
//rAB rAB rAB mB mA 
//4 5 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<63>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 65
//rAB rAB rAB mB mA 
//5 4 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<64>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 66
//rAB rAB rAB mB mA 
//5 3 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<65>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 67
//rAB rAB rAB mB mA 
//3 5 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<66>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 68
//rAB rAB rAB mB mA 
//3 4 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<67>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 69
//rAB rAB mB rAB mA 
//3 4 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<68>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 70
//rAB rAB mB mA rAB 
//3 4 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<69>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 71
//rAB mB rAB mA rAB 
//3 2 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<70>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 72
//rAB mB rAB rAB mA 
//3 2 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<71>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 73
//rAB mB rAB rAB mA 
//3 2 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<72>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 74
//rAB rAB mB rAB mA 
//3 5 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<73>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 75
//rAB rAB mB rAB mA 
//5 3 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<74>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 76
//rAB rAB mB mA rAB 
//5 3 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<75>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 77
//rAB rAB mB mA rAB 
//3 5 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<76>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 78
//rAB mB rAB mA rAB 
//3 2 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<77>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 79
//rAB mB mA rAB rAB 
//3 2 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<78>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 80
//rAB mB mA rAB rAB 
//3 2 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<79>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 81
//mB rAB mA rAB rAB 
//2 3 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<80>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 82
//mB rAB mA rAB rAB 
//2 3 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<81>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 83
//mB rAB rAB mA rAB 
//2 3 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<82>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 84
//mB rAB rAB mA rAB 
//2 5 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<83>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 85
//rAB mB rAB mA rAB 
//5 2 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<84>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 86
//rAB mB rAB rAB mA 
//5 2 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<85>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 87
//mB rAB rAB rAB mA 
//2 5 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<86>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
            {
               map(res, mul(B), A1);
            }, A2, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 88
//mB rAB rAB rAB mA 
//2 3 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<87>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
            {
               map(res, mul(B), A1);
            }, A2, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 89
//mB rAB rAB rAB mA 
//2 3 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<88>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
            {
               map(res, mul(B), A1);
            }, A2, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 90
//mB rAB rAB mA rAB 
//2 3 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<89>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 91
//mB rAB rAB mA rAB 
//2 4 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<90>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 92
//mB rAB rAB rAB mA 
//2 4 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<91>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
            {
               map(res, mul(B), A1);
            }, A2, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 93
//mB rAB rAB rAB mA 
//2 4 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<92>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
            {
               map(res, mul(B), A1);
            }, A2, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 94
//mB rAB rAB rAB mA 
//2 5 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<93>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
            {
               map(res, mul(B), A1);
            }, A2, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 95
//rAB mB rAB rAB mA 
//5 2 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<94>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 96
//rAB rAB mB rAB mA 
//5 4 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<95>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 97
//rAB rAB mB rAB mA 
//4 5 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<96>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 98
//rAB mB rAB rAB mA 
//4 2 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<97>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 99
//rAB mB rAB rAB mA 
//4 2 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<98>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<2>( flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 100
//rAB mB rAB mA rAB 
//4 2 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<99>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 101
//rAB mB mA rAB rAB 
//4 2 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<100>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 102
//rAB mB mA rAB rAB 
//4 2 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<101>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 103
//rAB mB rAB mA rAB 
//4 2 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<102>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 104
//rAB rAB mB mA rAB 
//4 5 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<103>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 105
//rAB rAB mB mA rAB 
//5 4 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<104>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 106
//rAB mB rAB mA rAB 
//5 2 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<105>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 107
//mB rAB rAB mA rAB 
//2 5 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<106>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 108
//mB rAB rAB mA rAB 
//2 4 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<107>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<1>( flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 109
//mB rAB mA rAB rAB 
//2 4 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<108>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 110
//mB rAB mA rAB rAB 
//2 4 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<109>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 111
//mB mA rAB rAB rAB 
//2 1 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<110>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 112
//mB mA rAB rAB rAB 
//2 1 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<111>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 113
//mB mA rAB rAB rAB 
//2 1 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<112>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 114
//mB rAB mA rAB rAB 
//2 5 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<113>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 115
//rAB mB mA rAB rAB 
//5 2 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<114>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 116
//rAB mB mA rAB rAB 
//5 2 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<115>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( subdiv<1, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t22 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t22, lift(lift(add)), [&](auto res, auto A3, auto B3)
   {
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
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t22);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 117
//mB rAB mA rAB rAB 
//2 5 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<116>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = flip<0>( subdiv<1, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t21 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t21, lift(add), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t21);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 118
//mB mA rAB rAB rAB 
//2 1 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<117>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 119
//mB mA rAB rAB rAB 
//2 1 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<118>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 120
//mB mA rAB rAB rAB 
//2 1 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<119>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( res_ );
   auto A4 = subdiv<1, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<1, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t20 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
      {
         rnz(res, t20, add, [&](auto res, auto A2, auto B2)
         {
            rnz(res, t10, add, [&](auto res, auto A1, auto B1)
            {
               rnz(res, t00, add, mul, A1, B1);
            }, A2, B2);
         }, A3, B3);
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   Deallocate(t20);
   return ms(time0, time1);
}


