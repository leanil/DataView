//permutation: 1
//mA mA mB mB rAB rAB 
//1 2 3 4 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<0>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 2
//mA mA mB mB rAB rAB 
//1 2 3 4 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<1>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 3
//mA mA mB rAB mB rAB 
//1 2 3 6 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<2>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 4
//mA mA rAB mB mB rAB 
//1 2 6 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<3>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 5
//mA rAB mA mB mB rAB 
//1 6 2 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<4>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 6
//rAB mA mA mB mB rAB 
//6 1 2 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<5>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 7
//rAB mA mA mB rAB mB 
//6 1 2 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<6>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 8
//mA rAB mA mB rAB mB 
//1 6 2 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<7>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 9
//mA mA rAB mB rAB mB 
//1 2 6 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<8>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 10
//mA mA mB rAB rAB mB 
//1 2 3 6 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<9>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 11
//mA mA mB rAB rAB mB 
//1 2 3 5 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<10>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 12
//mA mA mB rAB mB rAB 
//1 2 3 5 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<11>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 13
//mA mA rAB mB mB rAB 
//1 2 5 3 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<12>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 14
//mA mA rAB mB rAB mB 
//1 2 5 3 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<13>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 15
//mA mA rAB rAB mB mB 
//1 2 5 6 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<14>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 16
//mA mA rAB rAB mB mB 
//1 2 6 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<15>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 17
//mA rAB mA rAB mB mB 
//1 6 2 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<16>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 18
//rAB mA mA rAB mB mB 
//6 1 2 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<17>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 19
//rAB mA rAB mA mB mB 
//6 1 5 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<18>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 20
//mA rAB rAB mA mB mB 
//1 6 5 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<19>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 21
//mA rAB rAB mA mB mB 
//1 5 6 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<20>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 22
//mA rAB mA rAB mB mB 
//1 5 2 6 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<21>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 23
//mA rAB mA mB rAB mB 
//1 5 2 3 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<22>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 24
//mA rAB mA mB mB rAB 
//1 5 2 3 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<23>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 25
//rAB mA mA mB mB rAB 
//5 1 2 3 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<24>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 26
//rAB mA mA mB rAB mB 
//5 1 2 3 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<25>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 27
//rAB mA mA rAB mB mB 
//5 1 2 6 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<26>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 28
//rAB mA rAB mA mB mB 
//5 1 6 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<27>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 29
//rAB rAB mA mA mB mB 
//5 6 1 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<28>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 30
//rAB rAB mA mA mB mB 
//6 5 1 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<29>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 31
//rAB rAB mA mA mB mB 
//6 5 1 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<30>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 32
//rAB rAB mA mA mB mB 
//5 6 1 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<31>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 33
//rAB mA rAB mA mB mB 
//5 1 6 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<32>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 34
//rAB mA mA rAB mB mB 
//5 1 2 6 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<33>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 35
//rAB mA mA mB rAB mB 
//5 1 2 4 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<34>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 36
//rAB mA mA mB mB rAB 
//5 1 2 4 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<35>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 37
//mA rAB mA mB mB rAB 
//1 5 2 4 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<36>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 38
//mA rAB mA mB rAB mB 
//1 5 2 4 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<37>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 39
//mA rAB mA rAB mB mB 
//1 5 2 6 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<38>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 40
//mA rAB rAB mA mB mB 
//1 5 6 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<39>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 41
//mA rAB rAB mA mB mB 
//1 6 5 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<40>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 42
//rAB mA rAB mA mB mB 
//6 1 5 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<41>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 43
//rAB mA mA rAB mB mB 
//6 1 2 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<42>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 44
//mA rAB mA rAB mB mB 
//1 6 2 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<43>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 45
//mA mA rAB rAB mB mB 
//1 2 6 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<44>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 46
//mA mA rAB rAB mB mB 
//1 2 5 6 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<45>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 47
//mA mA rAB mB rAB mB 
//1 2 5 4 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<46>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 48
//mA mA rAB mB mB rAB 
//1 2 5 4 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<47>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 49
//mA mA mB rAB mB rAB 
//1 2 4 5 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<48>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 50
//mA mA mB rAB rAB mB 
//1 2 4 5 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<49>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 51
//mA mA mB rAB rAB mB 
//1 2 4 6 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<50>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 52
//mA mA rAB mB rAB mB 
//1 2 6 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<51>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 53
//mA rAB mA mB rAB mB 
//1 6 2 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<52>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 54
//rAB mA mA mB rAB mB 
//6 1 2 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<53>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 55
//rAB mA mA mB mB rAB 
//6 1 2 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<54>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 56
//mA rAB mA mB mB rAB 
//1 6 2 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<55>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 57
//mA mA rAB mB mB rAB 
//1 2 6 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<56>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 58
//mA mA mB rAB mB rAB 
//1 2 4 6 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<57>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 59
//mA mA mB mB rAB rAB 
//1 2 4 3 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<58>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 60
//mA mA mB mB rAB rAB 
//1 2 4 3 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<59>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 61
//mA mB mA mB rAB rAB 
//1 4 2 3 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<60>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 62
//mA mB mA mB rAB rAB 
//1 4 2 3 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<61>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 63
//mA mB mA rAB mB rAB 
//1 4 2 6 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<62>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 64
//mA mB rAB mA mB rAB 
//1 4 6 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<63>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 65
//mA rAB mB mA mB rAB 
//1 6 4 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<64>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 66
//rAB mA mB mA mB rAB 
//6 1 4 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<65>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 67
//rAB mA mB mA rAB mB 
//6 1 4 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<66>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 68
//mA rAB mB mA rAB mB 
//1 6 4 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<67>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 69
//mA mB rAB mA rAB mB 
//1 4 6 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<68>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 70
//mA mB mA rAB rAB mB 
//1 4 2 6 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<69>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 71
//mA mB mA rAB rAB mB 
//1 4 2 5 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<70>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 72
//mA mB mA rAB mB rAB 
//1 4 2 5 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<71>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 73
//mA mB rAB mA mB rAB 
//1 4 5 2 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<72>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 74
//mA mB rAB mA rAB mB 
//1 4 5 2 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<73>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 75
//mA mB rAB rAB mA mB 
//1 4 5 6 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<74>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 76
//mA mB rAB rAB mA mB 
//1 4 6 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<75>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 77
//mA rAB mB rAB mA mB 
//1 6 4 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<76>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 78
//rAB mA mB rAB mA mB 
//6 1 4 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<77>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 79
//rAB mA rAB mB mA mB 
//6 1 5 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<78>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 80
//mA rAB rAB mB mA mB 
//1 6 5 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<79>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 81
//mA rAB rAB mB mA mB 
//1 5 6 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<80>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 82
//mA rAB mB rAB mA mB 
//1 5 4 6 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<81>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 83
//mA rAB mB mA rAB mB 
//1 5 4 2 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<82>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 84
//mA rAB mB mA mB rAB 
//1 5 4 2 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<83>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 85
//rAB mA mB mA mB rAB 
//5 1 4 2 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<84>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 86
//rAB mA mB mA rAB mB 
//5 1 4 2 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<85>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 87
//rAB mA mB rAB mA mB 
//5 1 4 6 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<86>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 88
//rAB mA rAB mB mA mB 
//5 1 6 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<87>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 89
//rAB rAB mA mB mA mB 
//5 6 1 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<88>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 90
//rAB rAB mA mB mA mB 
//6 5 1 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<89>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 91
//rAB rAB mB mA mA mB 
//6 5 4 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<90>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 92
//rAB rAB mB mA mA mB 
//5 6 4 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<91>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 93
//rAB mB rAB mA mA mB 
//5 4 6 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<92>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 94
//rAB mB mA rAB mA mB 
//5 4 1 6 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<93>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 95
//rAB mB mA mA rAB mB 
//5 4 1 2 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<94>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 96
//rAB mB mA mA mB rAB 
//5 4 1 2 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<95>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 97
//mB rAB mA mA mB rAB 
//4 5 1 2 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<96>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 98
//mB rAB mA mA rAB mB 
//4 5 1 2 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<97>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 99
//mB rAB mA rAB mA mB 
//4 5 1 6 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<98>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 100
//mB rAB rAB mA mA mB 
//4 5 6 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<99>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 101
//mB rAB rAB mA mA mB 
//4 6 5 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<100>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 102
//rAB mB rAB mA mA mB 
//6 4 5 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<101>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 103
//rAB mB mA rAB mA mB 
//6 4 1 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<102>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 104
//mB rAB mA rAB mA mB 
//4 6 1 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<103>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 105
//mB mA rAB rAB mA mB 
//4 1 6 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<104>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 106
//mB mA rAB rAB mA mB 
//4 1 5 6 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<105>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 107
//mB mA rAB mA rAB mB 
//4 1 5 2 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<106>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 108
//mB mA rAB mA mB rAB 
//4 1 5 2 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<107>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 109
//mB mA mA rAB mB rAB 
//4 1 2 5 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<108>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 110
//mB mA mA rAB rAB mB 
//4 1 2 5 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<109>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 111
//mB mA mA rAB rAB mB 
//4 1 2 6 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<110>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 112
//mB mA rAB mA rAB mB 
//4 1 6 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<111>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 113
//mB rAB mA mA rAB mB 
//4 6 1 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<112>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 114
//rAB mB mA mA rAB mB 
//6 4 1 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<113>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 115
//rAB mB mA mA mB rAB 
//6 4 1 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<114>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 116
//mB rAB mA mA mB rAB 
//4 6 1 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<115>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 117
//mB mA rAB mA mB rAB 
//4 1 6 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<116>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 118
//mB mA mA rAB mB rAB 
//4 1 2 6 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<117>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 119
//mB mA mA mB rAB rAB 
//4 1 2 3 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<118>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 120
//mB mA mA mB rAB rAB 
//4 1 2 3 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<119>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 121
//mB mA mB mA rAB rAB 
//4 1 3 2 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<120>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 122
//mB mA mB mA rAB rAB 
//4 1 3 2 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<121>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 123
//mB mA mB rAB mA rAB 
//4 1 3 6 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<122>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 124
//mB mA rAB mB mA rAB 
//4 1 6 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<123>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 125
//mB rAB mA mB mA rAB 
//4 6 1 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<124>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 126
//rAB mB mA mB mA rAB 
//6 4 1 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<125>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 127
//rAB mB mA mB rAB mA 
//6 4 1 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<126>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 128
//mB rAB mA mB rAB mA 
//4 6 1 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<127>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 129
//mB mA rAB mB rAB mA 
//4 1 6 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<128>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 130
//mB mA mB rAB rAB mA 
//4 1 3 6 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<129>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 131
//mB mA mB rAB rAB mA 
//4 1 3 5 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<130>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 132
//mB mA mB rAB mA rAB 
//4 1 3 5 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<131>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 133
//mB mA rAB mB mA rAB 
//4 1 5 3 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<132>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 134
//mB mA rAB mB rAB mA 
//4 1 5 3 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<133>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 135
//mB mA rAB rAB mB mA 
//4 1 5 6 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<134>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 136
//mB mA rAB rAB mB mA 
//4 1 6 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<135>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 137
//mB rAB mA rAB mB mA 
//4 6 1 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<136>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 138
//rAB mB mA rAB mB mA 
//6 4 1 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<137>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 139
//rAB mB rAB mA mB mA 
//6 4 5 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<138>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 140
//mB rAB rAB mA mB mA 
//4 6 5 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<139>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 141
//mB rAB rAB mA mB mA 
//4 5 6 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<140>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 142
//mB rAB mA rAB mB mA 
//4 5 1 6 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<141>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 143
//mB rAB mA mB rAB mA 
//4 5 1 3 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<142>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 144
//mB rAB mA mB mA rAB 
//4 5 1 3 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<143>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 145
//rAB mB mA mB mA rAB 
//5 4 1 3 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<144>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 146
//rAB mB mA mB rAB mA 
//5 4 1 3 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<145>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 147
//rAB mB mA rAB mB mA 
//5 4 1 6 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<146>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 148
//rAB mB rAB mA mB mA 
//5 4 6 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<147>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 149
//rAB rAB mB mA mB mA 
//5 6 4 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<148>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 150
//rAB rAB mB mA mB mA 
//6 5 4 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<149>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 151
//rAB rAB mA mB mB mA 
//6 5 1 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<150>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 152
//rAB rAB mA mB mB mA 
//5 6 1 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<151>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 153
//rAB mA rAB mB mB mA 
//5 1 6 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<152>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 154
//rAB mA mB rAB mB mA 
//5 1 4 6 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<153>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 155
//rAB mA mB mB rAB mA 
//5 1 4 3 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<154>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 156
//rAB mA mB mB mA rAB 
//5 1 4 3 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<155>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 157
//mA rAB mB mB mA rAB 
//1 5 4 3 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<156>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 158
//mA rAB mB mB rAB mA 
//1 5 4 3 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<157>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 159
//mA rAB mB rAB mB mA 
//1 5 4 6 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<158>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 160
//mA rAB rAB mB mB mA 
//1 5 6 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<159>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 161
//mA rAB rAB mB mB mA 
//1 6 5 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<160>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 162
//rAB mA rAB mB mB mA 
//6 1 5 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<161>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 163
//rAB mA mB rAB mB mA 
//6 1 4 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<162>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 164
//mA rAB mB rAB mB mA 
//1 6 4 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<163>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 165
//mA mB rAB rAB mB mA 
//1 4 6 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<164>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 166
//mA mB rAB rAB mB mA 
//1 4 5 6 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<165>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 167
//mA mB rAB mB rAB mA 
//1 4 5 3 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<166>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 168
//mA mB rAB mB mA rAB 
//1 4 5 3 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<167>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 169
//mA mB mB rAB mA rAB 
//1 4 3 5 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<168>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 170
//mA mB mB rAB rAB mA 
//1 4 3 5 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<169>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 171
//mA mB mB rAB rAB mA 
//1 4 3 6 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<170>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 172
//mA mB rAB mB rAB mA 
//1 4 6 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<171>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 173
//mA rAB mB mB rAB mA 
//1 6 4 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<172>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 174
//rAB mA mB mB rAB mA 
//6 1 4 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<173>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 175
//rAB mA mB mB mA rAB 
//6 1 4 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<174>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 176
//mA rAB mB mB mA rAB 
//1 6 4 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<175>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 177
//mA mB rAB mB mA rAB 
//1 4 6 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<176>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 178
//mA mB mB rAB mA rAB 
//1 4 3 6 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<177>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 179
//mA mB mB mA rAB rAB 
//1 4 3 2 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<178>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 180
//mA mB mB mA rAB rAB 
//1 4 3 2 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<179>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 181
//mA mB mB mA rAB rAB 
//1 3 4 2 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<180>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 182
//mA mB mB mA rAB rAB 
//1 3 4 2 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<181>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 183
//mA mB mB rAB mA rAB 
//1 3 4 6 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<182>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 184
//mA mB rAB mB mA rAB 
//1 3 6 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<183>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 185
//mA rAB mB mB mA rAB 
//1 6 3 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<184>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 186
//rAB mA mB mB mA rAB 
//6 1 3 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<185>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 187
//rAB mA mB mB rAB mA 
//6 1 3 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<186>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 188
//mA rAB mB mB rAB mA 
//1 6 3 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<187>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 189
//mA mB rAB mB rAB mA 
//1 3 6 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<188>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 190
//mA mB mB rAB rAB mA 
//1 3 4 6 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<189>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 191
//mA mB mB rAB rAB mA 
//1 3 4 5 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<190>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 192
//mA mB mB rAB mA rAB 
//1 3 4 5 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<191>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 193
//mA mB rAB mB mA rAB 
//1 3 5 4 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<192>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 194
//mA mB rAB mB rAB mA 
//1 3 5 4 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<193>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 195
//mA mB rAB rAB mB mA 
//1 3 5 6 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<194>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 196
//mA mB rAB rAB mB mA 
//1 3 6 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<195>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 197
//mA rAB mB rAB mB mA 
//1 6 3 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<196>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 198
//rAB mA mB rAB mB mA 
//6 1 3 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<197>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 199
//rAB mA rAB mB mB mA 
//6 1 5 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<198>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 200
//mA rAB rAB mB mB mA 
//1 6 5 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<199>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 201
//mA rAB rAB mB mB mA 
//1 5 6 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<200>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 202
//mA rAB mB rAB mB mA 
//1 5 3 6 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<201>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 203
//mA rAB mB mB rAB mA 
//1 5 3 4 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<202>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 204
//mA rAB mB mB mA rAB 
//1 5 3 4 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<203>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 205
//rAB mA mB mB mA rAB 
//5 1 3 4 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<204>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 206
//rAB mA mB mB rAB mA 
//5 1 3 4 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<205>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 207
//rAB mA mB rAB mB mA 
//5 1 3 6 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<206>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 208
//rAB mA rAB mB mB mA 
//5 1 6 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<207>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 209
//rAB rAB mA mB mB mA 
//5 6 1 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<208>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 210
//rAB rAB mA mB mB mA 
//6 5 1 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<209>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 211
//rAB rAB mA mB mA mB 
//6 5 1 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<210>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 212
//rAB rAB mA mB mA mB 
//5 6 1 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<211>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 213
//rAB mA rAB mB mA mB 
//5 1 6 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<212>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 214
//rAB mA mB rAB mA mB 
//5 1 3 6 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<213>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 215
//rAB mA mB mA rAB mB 
//5 1 3 2 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<214>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 216
//rAB mA mB mA mB rAB 
//5 1 3 2 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<215>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 217
//mA rAB mB mA mB rAB 
//1 5 3 2 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<216>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 218
//mA rAB mB mA rAB mB 
//1 5 3 2 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<217>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 219
//mA rAB mB rAB mA mB 
//1 5 3 6 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<218>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 220
//mA rAB rAB mB mA mB 
//1 5 6 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<219>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 221
//mA rAB rAB mB mA mB 
//1 6 5 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<220>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 222
//rAB mA rAB mB mA mB 
//6 1 5 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<221>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 223
//rAB mA mB rAB mA mB 
//6 1 3 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<222>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 224
//mA rAB mB rAB mA mB 
//1 6 3 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<223>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 225
//mA mB rAB rAB mA mB 
//1 3 6 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<224>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 226
//mA mB rAB rAB mA mB 
//1 3 5 6 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<225>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 227
//mA mB rAB mA rAB mB 
//1 3 5 2 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<226>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 228
//mA mB rAB mA mB rAB 
//1 3 5 2 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<227>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 229
//mA mB mA rAB mB rAB 
//1 3 2 5 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<228>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 230
//mA mB mA rAB rAB mB 
//1 3 2 5 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<229>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 231
//mA mB mA rAB rAB mB 
//1 3 2 6 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<230>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 232
//mA mB rAB mA rAB mB 
//1 3 6 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<231>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 233
//mA rAB mB mA rAB mB 
//1 6 3 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<232>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 234
//rAB mA mB mA rAB mB 
//6 1 3 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<233>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 235
//rAB mA mB mA mB rAB 
//6 1 3 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<234>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 236
//mA rAB mB mA mB rAB 
//1 6 3 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<235>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 237
//mA mB rAB mA mB rAB 
//1 3 6 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<236>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 238
//mA mB mA rAB mB rAB 
//1 3 2 6 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<237>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 239
//mA mB mA mB rAB rAB 
//1 3 2 4 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<238>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 240
//mA mB mA mB rAB rAB 
//1 3 2 4 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<239>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 241
//mB mA mA mB rAB rAB 
//3 1 2 4 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<240>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 242
//mB mA mA mB rAB rAB 
//3 1 2 4 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<241>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 243
//mB mA mA rAB mB rAB 
//3 1 2 6 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<242>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 244
//mB mA rAB mA mB rAB 
//3 1 6 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<243>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 245
//mB rAB mA mA mB rAB 
//3 6 1 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<244>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 246
//rAB mB mA mA mB rAB 
//6 3 1 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<245>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 247
//rAB mB mA mA rAB mB 
//6 3 1 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<246>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 248
//mB rAB mA mA rAB mB 
//3 6 1 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<247>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 249
//mB mA rAB mA rAB mB 
//3 1 6 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<248>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 250
//mB mA mA rAB rAB mB 
//3 1 2 6 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<249>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 251
//mB mA mA rAB rAB mB 
//3 1 2 5 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<250>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 252
//mB mA mA rAB mB rAB 
//3 1 2 5 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<251>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 253
//mB mA rAB mA mB rAB 
//3 1 5 2 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<252>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 254
//mB mA rAB mA rAB mB 
//3 1 5 2 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<253>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 255
//mB mA rAB rAB mA mB 
//3 1 5 6 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<254>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 256
//mB mA rAB rAB mA mB 
//3 1 6 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<255>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 257
//mB rAB mA rAB mA mB 
//3 6 1 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<256>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 258
//rAB mB mA rAB mA mB 
//6 3 1 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<257>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 259
//rAB mB rAB mA mA mB 
//6 3 5 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<258>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 260
//mB rAB rAB mA mA mB 
//3 6 5 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<259>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 261
//mB rAB rAB mA mA mB 
//3 5 6 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<260>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 262
//mB rAB mA rAB mA mB 
//3 5 1 6 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<261>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 263
//mB rAB mA mA rAB mB 
//3 5 1 2 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<262>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 264
//mB rAB mA mA mB rAB 
//3 5 1 2 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<263>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 265
//rAB mB mA mA mB rAB 
//5 3 1 2 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<264>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 266
//rAB mB mA mA rAB mB 
//5 3 1 2 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<265>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 267
//rAB mB mA rAB mA mB 
//5 3 1 6 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<266>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 268
//rAB mB rAB mA mA mB 
//5 3 6 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<267>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 269
//rAB rAB mB mA mA mB 
//5 6 3 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<268>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 270
//rAB rAB mB mA mA mB 
//6 5 3 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<269>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 271
//rAB rAB mB mA mB mA 
//6 5 3 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<270>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 272
//rAB rAB mB mA mB mA 
//5 6 3 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<271>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 273
//rAB mB rAB mA mB mA 
//5 3 6 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<272>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 274
//rAB mB mA rAB mB mA 
//5 3 1 6 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<273>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 275
//rAB mB mA mB rAB mA 
//5 3 1 4 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<274>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 276
//rAB mB mA mB mA rAB 
//5 3 1 4 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<275>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 277
//mB rAB mA mB mA rAB 
//3 5 1 4 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<276>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 278
//mB rAB mA mB rAB mA 
//3 5 1 4 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<277>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 279
//mB rAB mA rAB mB mA 
//3 5 1 6 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<278>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 280
//mB rAB rAB mA mB mA 
//3 5 6 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<279>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 281
//mB rAB rAB mA mB mA 
//3 6 5 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<280>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 282
//rAB mB rAB mA mB mA 
//6 3 5 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<281>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 283
//rAB mB mA rAB mB mA 
//6 3 1 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<282>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 284
//mB rAB mA rAB mB mA 
//3 6 1 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<283>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 285
//mB mA rAB rAB mB mA 
//3 1 6 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<284>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 286
//mB mA rAB rAB mB mA 
//3 1 5 6 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<285>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 287
//mB mA rAB mB rAB mA 
//3 1 5 4 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<286>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 288
//mB mA rAB mB mA rAB 
//3 1 5 4 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<287>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 289
//mB mA mB rAB mA rAB 
//3 1 4 5 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<288>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 290
//mB mA mB rAB rAB mA 
//3 1 4 5 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<289>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 291
//mB mA mB rAB rAB mA 
//3 1 4 6 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<290>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 292
//mB mA rAB mB rAB mA 
//3 1 6 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<291>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 293
//mB rAB mA mB rAB mA 
//3 6 1 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<292>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 294
//rAB mB mA mB rAB mA 
//6 3 1 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<293>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 295
//rAB mB mA mB mA rAB 
//6 3 1 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<294>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 296
//mB rAB mA mB mA rAB 
//3 6 1 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<295>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 297
//mB mA rAB mB mA rAB 
//3 1 6 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<296>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 298
//mB mA mB rAB mA rAB 
//3 1 4 6 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<297>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 299
//mB mA mB mA rAB rAB 
//3 1 4 2 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<298>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 300
//mB mA mB mA rAB rAB 
//3 1 4 2 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<299>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 301
//mB mB mA mA rAB rAB 
//3 4 1 2 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<300>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 302
//mB mB mA mA rAB rAB 
//3 4 1 2 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<301>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 303
//mB mB mA rAB mA rAB 
//3 4 1 6 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<302>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 304
//mB mB rAB mA mA rAB 
//3 4 6 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<303>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 305
//mB rAB mB mA mA rAB 
//3 6 4 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<304>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 306
//rAB mB mB mA mA rAB 
//6 3 4 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<305>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 307
//rAB mB mB mA rAB mA 
//6 3 4 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<306>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 308
//mB rAB mB mA rAB mA 
//3 6 4 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<307>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 309
//mB mB rAB mA rAB mA 
//3 4 6 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<308>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 310
//mB mB mA rAB rAB mA 
//3 4 1 6 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<309>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 311
//mB mB mA rAB rAB mA 
//3 4 1 5 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<310>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 312
//mB mB mA rAB mA rAB 
//3 4 1 5 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<311>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 313
//mB mB rAB mA mA rAB 
//3 4 5 1 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<312>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 314
//mB mB rAB mA rAB mA 
//3 4 5 1 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<313>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 315
//mB mB rAB rAB mA mA 
//3 4 5 6 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<314>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 316
//mB mB rAB rAB mA mA 
//3 4 6 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<315>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 317
//mB rAB mB rAB mA mA 
//3 6 4 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<316>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 318
//rAB mB mB rAB mA mA 
//6 3 4 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<317>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 319
//rAB mB rAB mB mA mA 
//6 3 5 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<318>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 320
//mB rAB rAB mB mA mA 
//3 6 5 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<319>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 321
//mB rAB rAB mB mA mA 
//3 5 6 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<320>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 322
//mB rAB mB rAB mA mA 
//3 5 4 6 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<321>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 323
//mB rAB mB mA rAB mA 
//3 5 4 1 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<322>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 324
//mB rAB mB mA mA rAB 
//3 5 4 1 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<323>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 325
//rAB mB mB mA mA rAB 
//5 3 4 1 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<324>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 326
//rAB mB mB mA rAB mA 
//5 3 4 1 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<325>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 327
//rAB mB mB rAB mA mA 
//5 3 4 6 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<326>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 328
//rAB mB rAB mB mA mA 
//5 3 6 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<327>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 329
//rAB rAB mB mB mA mA 
//5 6 3 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<328>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 330
//rAB rAB mB mB mA mA 
//6 5 3 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<329>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 331
//rAB rAB mB mB mA mA 
//6 5 4 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<330>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 332
//rAB rAB mB mB mA mA 
//5 6 4 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<331>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 333
//rAB mB rAB mB mA mA 
//5 4 6 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<332>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 334
//rAB mB mB rAB mA mA 
//5 4 3 6 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<333>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 335
//rAB mB mB mA rAB mA 
//5 4 3 1 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<334>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 336
//rAB mB mB mA mA rAB 
//5 4 3 1 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<335>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 337
//mB rAB mB mA mA rAB 
//4 5 3 1 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<336>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 338
//mB rAB mB mA rAB mA 
//4 5 3 1 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<337>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 339
//mB rAB mB rAB mA mA 
//4 5 3 6 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<338>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 340
//mB rAB rAB mB mA mA 
//4 5 6 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<339>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 341
//mB rAB rAB mB mA mA 
//4 6 5 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<340>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 342
//rAB mB rAB mB mA mA 
//6 4 5 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<341>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 343
//rAB mB mB rAB mA mA 
//6 4 3 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<342>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 344
//mB rAB mB rAB mA mA 
//4 6 3 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<343>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 345
//mB mB rAB rAB mA mA 
//4 3 6 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<344>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 346
//mB mB rAB rAB mA mA 
//4 3 5 6 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<345>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 347
//mB mB rAB mA rAB mA 
//4 3 5 1 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<346>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 348
//mB mB rAB mA mA rAB 
//4 3 5 1 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<347>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 349
//mB mB mA rAB mA rAB 
//4 3 1 5 2 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<348>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 350
//mB mB mA rAB rAB mA 
//4 3 1 5 6 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<349>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 351
//mB mB mA rAB rAB mA 
//4 3 1 6 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<350>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 352
//mB mB rAB mA rAB mA 
//4 3 6 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<351>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 353
//mB rAB mB mA rAB mA 
//4 6 3 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<352>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 354
//rAB mB mB mA rAB mA 
//6 4 3 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<353>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 355
//rAB mB mB mA mA rAB 
//6 4 3 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<354>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 356
//mB rAB mB mA mA rAB 
//4 6 3 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<355>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 357
//mB mB rAB mA mA rAB 
//4 3 6 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<356>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 358
//mB mB mA rAB mA rAB 
//4 3 1 6 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<357>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 359
//mB mB mA mA rAB rAB 
//4 3 1 2 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<358>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 360
//mB mB mA mA rAB rAB 
//4 3 1 2 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<359>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 361
//mB mB mA mA rAB rAB 
//4 3 2 1 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<360>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 362
//mB mB mA mA rAB rAB 
//4 3 2 1 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<361>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 363
//mB mB mA rAB mA rAB 
//4 3 2 6 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<362>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 364
//mB mB rAB mA mA rAB 
//4 3 6 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<363>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 365
//mB rAB mB mA mA rAB 
//4 6 3 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<364>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 366
//rAB mB mB mA mA rAB 
//6 4 3 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<365>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 367
//rAB mB mB mA rAB mA 
//6 4 3 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<366>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 368
//mB rAB mB mA rAB mA 
//4 6 3 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<367>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 369
//mB mB rAB mA rAB mA 
//4 3 6 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<368>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 370
//mB mB mA rAB rAB mA 
//4 3 2 6 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<369>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 371
//mB mB mA rAB rAB mA 
//4 3 2 5 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<370>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 372
//mB mB mA rAB mA rAB 
//4 3 2 5 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<371>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 373
//mB mB rAB mA mA rAB 
//4 3 5 2 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<372>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 374
//mB mB rAB mA rAB mA 
//4 3 5 2 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<373>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 375
//mB mB rAB rAB mA mA 
//4 3 5 6 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<374>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 376
//mB mB rAB rAB mA mA 
//4 3 6 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<375>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 377
//mB rAB mB rAB mA mA 
//4 6 3 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<376>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 378
//rAB mB mB rAB mA mA 
//6 4 3 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<377>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 379
//rAB mB rAB mB mA mA 
//6 4 5 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<378>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 380
//mB rAB rAB mB mA mA 
//4 6 5 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<379>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 381
//mB rAB rAB mB mA mA 
//4 5 6 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<380>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 382
//mB rAB mB rAB mA mA 
//4 5 3 6 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<381>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 383
//mB rAB mB mA rAB mA 
//4 5 3 2 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<382>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 384
//mB rAB mB mA mA rAB 
//4 5 3 2 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<383>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 385
//rAB mB mB mA mA rAB 
//5 4 3 2 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<384>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 386
//rAB mB mB mA rAB mA 
//5 4 3 2 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<385>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 387
//rAB mB mB rAB mA mA 
//5 4 3 6 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<386>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 388
//rAB mB rAB mB mA mA 
//5 4 6 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<387>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 389
//rAB rAB mB mB mA mA 
//5 6 4 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<388>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 390
//rAB rAB mB mB mA mA 
//6 5 4 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<389>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 391
//rAB rAB mB mB mA mA 
//6 5 3 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<390>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 392
//rAB rAB mB mB mA mA 
//5 6 3 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<391>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 393
//rAB mB rAB mB mA mA 
//5 3 6 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<392>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 394
//rAB mB mB rAB mA mA 
//5 3 4 6 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<393>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 395
//rAB mB mB mA rAB mA 
//5 3 4 2 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<394>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 396
//rAB mB mB mA mA rAB 
//5 3 4 2 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<395>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 397
//mB rAB mB mA mA rAB 
//3 5 4 2 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<396>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 398
//mB rAB mB mA rAB mA 
//3 5 4 2 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<397>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 399
//mB rAB mB rAB mA mA 
//3 5 4 6 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<398>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 400
//mB rAB rAB mB mA mA 
//3 5 6 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<399>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 401
//mB rAB rAB mB mA mA 
//3 6 5 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<400>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 402
//rAB mB rAB mB mA mA 
//6 3 5 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<401>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, B1);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 403
//rAB mB mB rAB mA mA 
//6 3 4 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<402>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 404
//mB rAB mB rAB mA mA 
//3 6 4 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<403>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 405
//mB mB rAB rAB mA mA 
//3 4 6 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<404>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 406
//mB mB rAB rAB mA mA 
//3 4 5 6 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<405>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A2, auto B)
            {
               map(res, [&](auto res, auto A1)
               {
                  map(res, mul(B), A1);
               }, A2);
            }, A3, B1);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 407
//mB mB rAB mA rAB mA 
//3 4 5 2 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<406>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 408
//mB mB rAB mA mA rAB 
//3 4 5 2 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<407>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 409
//mB mB mA rAB mA rAB 
//3 4 2 5 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<408>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 410
//mB mB mA rAB rAB mA 
//3 4 2 5 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<409>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 411
//mB mB mA rAB rAB mA 
//3 4 2 6 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<410>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 412
//mB mB rAB mA rAB mA 
//3 4 6 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<411>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 413
//mB rAB mB mA rAB mA 
//3 6 4 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<412>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 414
//rAB mB mB mA rAB mA 
//6 3 4 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<413>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 415
//rAB mB mB mA mA rAB 
//6 3 4 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<414>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 416
//mB rAB mB mA mA rAB 
//3 6 4 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<415>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 417
//mB mB rAB mA mA rAB 
//3 4 6 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<416>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A3, auto B1)
         {
            map(res, [&](auto res, auto A2)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3);
         }, A4, B2);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 418
//mB mB mA rAB mA rAB 
//3 4 2 6 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<417>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A2, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, A3, B2);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 419
//mB mB mA mA rAB rAB 
//3 4 2 1 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<418>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 420
//mB mB mA mA rAB rAB 
//3 4 2 1 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<419>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A3)
         {
            map(res, [&](auto res, auto A2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, A3);
         }, A4);
      }, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 421
//mB mA mB mA rAB rAB 
//3 2 4 1 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<420>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 422
//mB mA mB mA rAB rAB 
//3 2 4 1 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<421>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 423
//mB mA mB rAB mA rAB 
//3 2 4 6 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<422>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 424
//mB mA rAB mB mA rAB 
//3 2 6 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<423>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 425
//mB rAB mA mB mA rAB 
//3 6 2 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<424>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 426
//rAB mB mA mB mA rAB 
//6 3 2 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<425>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 427
//rAB mB mA mB rAB mA 
//6 3 2 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<426>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 428
//mB rAB mA mB rAB mA 
//3 6 2 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<427>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 429
//mB mA rAB mB rAB mA 
//3 2 6 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<428>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 430
//mB mA mB rAB rAB mA 
//3 2 4 6 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<429>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 431
//mB mA mB rAB rAB mA 
//3 2 4 5 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<430>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 432
//mB mA mB rAB mA rAB 
//3 2 4 5 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<431>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 433
//mB mA rAB mB mA rAB 
//3 2 5 4 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<432>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 434
//mB mA rAB mB rAB mA 
//3 2 5 4 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<433>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 435
//mB mA rAB rAB mB mA 
//3 2 5 6 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<434>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 436
//mB mA rAB rAB mB mA 
//3 2 6 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<435>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 437
//mB rAB mA rAB mB mA 
//3 6 2 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<436>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 438
//rAB mB mA rAB mB mA 
//6 3 2 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<437>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 439
//rAB mB rAB mA mB mA 
//6 3 5 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<438>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 440
//mB rAB rAB mA mB mA 
//3 6 5 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<439>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 441
//mB rAB rAB mA mB mA 
//3 5 6 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<440>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 442
//mB rAB mA rAB mB mA 
//3 5 2 6 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<441>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 443
//mB rAB mA mB rAB mA 
//3 5 2 4 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<442>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 444
//mB rAB mA mB mA rAB 
//3 5 2 4 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<443>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 445
//rAB mB mA mB mA rAB 
//5 3 2 4 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<444>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 446
//rAB mB mA mB rAB mA 
//5 3 2 4 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<445>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 447
//rAB mB mA rAB mB mA 
//5 3 2 6 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<446>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 448
//rAB mB rAB mA mB mA 
//5 3 6 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<447>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 449
//rAB rAB mB mA mB mA 
//5 6 3 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<448>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 450
//rAB rAB mB mA mB mA 
//6 5 3 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<449>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 451
//rAB rAB mB mA mA mB 
//6 5 3 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<450>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 452
//rAB rAB mB mA mA mB 
//5 6 3 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<451>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 453
//rAB mB rAB mA mA mB 
//5 3 6 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<452>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 454
//rAB mB mA rAB mA mB 
//5 3 2 6 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<453>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 455
//rAB mB mA mA rAB mB 
//5 3 2 1 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<454>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 456
//rAB mB mA mA mB rAB 
//5 3 2 1 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<455>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 457
//mB rAB mA mA mB rAB 
//3 5 2 1 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<456>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 458
//mB rAB mA mA rAB mB 
//3 5 2 1 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<457>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 459
//mB rAB mA rAB mA mB 
//3 5 2 6 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<458>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 460
//mB rAB rAB mA mA mB 
//3 5 6 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<459>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 461
//mB rAB rAB mA mA mB 
//3 6 5 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<460>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 462
//rAB mB rAB mA mA mB 
//6 3 5 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<461>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 463
//rAB mB mA rAB mA mB 
//6 3 2 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<462>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 464
//mB rAB mA rAB mA mB 
//3 6 2 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<463>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 465
//mB mA rAB rAB mA mB 
//3 2 6 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<464>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 466
//mB mA rAB rAB mA mB 
//3 2 5 6 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<465>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 467
//mB mA rAB mA rAB mB 
//3 2 5 1 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<466>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 468
//mB mA rAB mA mB rAB 
//3 2 5 1 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<467>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 469
//mB mA mA rAB mB rAB 
//3 2 1 5 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<468>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 470
//mB mA mA rAB rAB mB 
//3 2 1 5 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<469>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 471
//mB mA mA rAB rAB mB 
//3 2 1 6 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<470>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 472
//mB mA rAB mA rAB mB 
//3 2 6 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<471>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 473
//mB rAB mA mA rAB mB 
//3 6 2 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<472>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 474
//rAB mB mA mA rAB mB 
//6 3 2 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<473>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 475
//rAB mB mA mA mB rAB 
//6 3 2 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<474>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 476
//mB rAB mA mA mB rAB 
//3 6 2 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<475>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 477
//mB mA rAB mA mB rAB 
//3 2 6 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<476>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 478
//mB mA mA rAB mB rAB 
//3 2 1 6 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<477>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 479
//mB mA mA mB rAB rAB 
//3 2 1 4 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<478>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 480
//mB mA mA mB rAB rAB 
//3 2 1 4 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<479>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 481
//mA mB mA mB rAB rAB 
//2 3 1 4 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<480>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 482
//mA mB mA mB rAB rAB 
//2 3 1 4 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<481>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 483
//mA mB mA rAB mB rAB 
//2 3 1 6 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<482>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 484
//mA mB rAB mA mB rAB 
//2 3 6 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<483>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 485
//mA rAB mB mA mB rAB 
//2 6 3 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<484>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 486
//rAB mA mB mA mB rAB 
//6 2 3 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<485>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 487
//rAB mA mB mA rAB mB 
//6 2 3 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<486>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 488
//mA rAB mB mA rAB mB 
//2 6 3 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<487>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 489
//mA mB rAB mA rAB mB 
//2 3 6 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<488>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 490
//mA mB mA rAB rAB mB 
//2 3 1 6 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<489>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 491
//mA mB mA rAB rAB mB 
//2 3 1 5 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<490>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 492
//mA mB mA rAB mB rAB 
//2 3 1 5 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<491>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 493
//mA mB rAB mA mB rAB 
//2 3 5 1 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<492>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 494
//mA mB rAB mA rAB mB 
//2 3 5 1 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<493>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 495
//mA mB rAB rAB mA mB 
//2 3 5 6 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<494>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 496
//mA mB rAB rAB mA mB 
//2 3 6 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<495>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 497
//mA rAB mB rAB mA mB 
//2 6 3 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<496>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 498
//rAB mA mB rAB mA mB 
//6 2 3 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<497>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 499
//rAB mA rAB mB mA mB 
//6 2 5 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<498>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 500
//mA rAB rAB mB mA mB 
//2 6 5 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<499>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 501
//mA rAB rAB mB mA mB 
//2 5 6 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<500>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 502
//mA rAB mB rAB mA mB 
//2 5 3 6 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<501>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 503
//mA rAB mB mA rAB mB 
//2 5 3 1 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<502>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 504
//mA rAB mB mA mB rAB 
//2 5 3 1 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<503>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 505
//rAB mA mB mA mB rAB 
//5 2 3 1 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<504>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 506
//rAB mA mB mA rAB mB 
//5 2 3 1 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<505>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 507
//rAB mA mB rAB mA mB 
//5 2 3 6 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<506>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 508
//rAB mA rAB mB mA mB 
//5 2 6 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<507>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 509
//rAB rAB mA mB mA mB 
//5 6 2 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<508>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 510
//rAB rAB mA mB mA mB 
//6 5 2 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<509>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 511
//rAB rAB mA mB mB mA 
//6 5 2 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<510>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 512
//rAB rAB mA mB mB mA 
//5 6 2 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<511>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 513
//rAB mA rAB mB mB mA 
//5 2 6 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<512>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 514
//rAB mA mB rAB mB mA 
//5 2 3 6 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<513>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 515
//rAB mA mB mB rAB mA 
//5 2 3 4 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<514>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 516
//rAB mA mB mB mA rAB 
//5 2 3 4 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<515>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 517
//mA rAB mB mB mA rAB 
//2 5 3 4 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<516>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 518
//mA rAB mB mB rAB mA 
//2 5 3 4 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<517>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 519
//mA rAB mB rAB mB mA 
//2 5 3 6 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<518>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 520
//mA rAB rAB mB mB mA 
//2 5 6 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<519>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 521
//mA rAB rAB mB mB mA 
//2 6 5 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<520>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 522
//rAB mA rAB mB mB mA 
//6 2 5 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<521>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 523
//rAB mA mB rAB mB mA 
//6 2 3 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<522>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 524
//mA rAB mB rAB mB mA 
//2 6 3 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<523>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 525
//mA mB rAB rAB mB mA 
//2 3 6 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<524>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 526
//mA mB rAB rAB mB mA 
//2 3 5 6 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<525>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 527
//mA mB rAB mB rAB mA 
//2 3 5 4 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<526>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 528
//mA mB rAB mB mA rAB 
//2 3 5 4 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<527>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 529
//mA mB mB rAB mA rAB 
//2 3 4 5 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<528>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 530
//mA mB mB rAB rAB mA 
//2 3 4 5 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<529>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 531
//mA mB mB rAB rAB mA 
//2 3 4 6 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<530>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 532
//mA mB rAB mB rAB mA 
//2 3 6 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<531>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 533
//mA rAB mB mB rAB mA 
//2 6 3 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<532>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 534
//rAB mA mB mB rAB mA 
//6 2 3 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<533>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 535
//rAB mA mB mB mA rAB 
//6 2 3 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<534>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 536
//mA rAB mB mB mA rAB 
//2 6 3 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<535>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 537
//mA mB rAB mB mA rAB 
//2 3 6 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<536>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 538
//mA mB mB rAB mA rAB 
//2 3 4 6 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<537>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 539
//mA mB mB mA rAB rAB 
//2 3 4 1 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<538>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 540
//mA mB mB mA rAB rAB 
//2 3 4 1 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<539>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 541
//mA mB mB mA rAB rAB 
//2 4 3 1 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<540>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 542
//mA mB mB mA rAB rAB 
//2 4 3 1 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<541>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 543
//mA mB mB rAB mA rAB 
//2 4 3 6 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<542>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 544
//mA mB rAB mB mA rAB 
//2 4 6 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<543>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 545
//mA rAB mB mB mA rAB 
//2 6 4 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<544>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 546
//rAB mA mB mB mA rAB 
//6 2 4 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<545>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 547
//rAB mA mB mB rAB mA 
//6 2 4 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<546>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 548
//mA rAB mB mB rAB mA 
//2 6 4 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<547>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 549
//mA mB rAB mB rAB mA 
//2 4 6 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<548>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 550
//mA mB mB rAB rAB mA 
//2 4 3 6 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<549>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 551
//mA mB mB rAB rAB mA 
//2 4 3 5 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<550>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 552
//mA mB mB rAB mA rAB 
//2 4 3 5 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<551>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 553
//mA mB rAB mB mA rAB 
//2 4 5 3 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<552>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 554
//mA mB rAB mB rAB mA 
//2 4 5 3 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<553>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 555
//mA mB rAB rAB mB mA 
//2 4 5 6 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<554>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 556
//mA mB rAB rAB mB mA 
//2 4 6 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<555>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 557
//mA rAB mB rAB mB mA 
//2 6 4 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<556>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 558
//rAB mA mB rAB mB mA 
//6 2 4 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<557>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 559
//rAB mA rAB mB mB mA 
//6 2 5 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<558>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 560
//mA rAB rAB mB mB mA 
//2 6 5 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<559>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 561
//mA rAB rAB mB mB mA 
//2 5 6 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<560>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 562
//mA rAB mB rAB mB mA 
//2 5 4 6 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<561>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 563
//mA rAB mB mB rAB mA 
//2 5 4 3 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<562>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 564
//mA rAB mB mB mA rAB 
//2 5 4 3 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<563>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 565
//rAB mA mB mB mA rAB 
//5 2 4 3 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<564>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 566
//rAB mA mB mB rAB mA 
//5 2 4 3 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<565>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 567
//rAB mA mB rAB mB mA 
//5 2 4 6 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<566>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 568
//rAB mA rAB mB mB mA 
//5 2 6 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<567>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 569
//rAB rAB mA mB mB mA 
//5 6 2 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<568>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 570
//rAB rAB mA mB mB mA 
//6 5 2 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<569>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 571
//rAB rAB mB mA mB mA 
//6 5 4 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<570>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 572
//rAB rAB mB mA mB mA 
//5 6 4 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<571>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 573
//rAB mB rAB mA mB mA 
//5 4 6 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<572>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 574
//rAB mB mA rAB mB mA 
//5 4 2 6 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<573>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 575
//rAB mB mA mB rAB mA 
//5 4 2 3 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<574>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 576
//rAB mB mA mB mA rAB 
//5 4 2 3 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<575>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 577
//mB rAB mA mB mA rAB 
//4 5 2 3 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<576>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 578
//mB rAB mA mB rAB mA 
//4 5 2 3 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<577>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 579
//mB rAB mA rAB mB mA 
//4 5 2 6 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<578>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 580
//mB rAB rAB mA mB mA 
//4 5 6 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<579>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 581
//mB rAB rAB mA mB mA 
//4 6 5 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<580>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 582
//rAB mB rAB mA mB mA 
//6 4 5 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<581>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 583
//rAB mB mA rAB mB mA 
//6 4 2 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<582>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 584
//mB rAB mA rAB mB mA 
//4 6 2 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<583>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto B)
               {
                  map(res, mul(B), A1);
               }, B1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 585
//mB mA rAB rAB mB mA 
//4 2 6 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<584>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 586
//mB mA rAB rAB mB mA 
//4 2 5 6 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<585>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 587
//mB mA rAB mB rAB mA 
//4 2 5 3 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<586>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 588
//mB mA rAB mB mA rAB 
//4 2 5 3 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<587>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 589
//mB mA mB rAB mA rAB 
//4 2 3 5 1 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<588>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 590
//mB mA mB rAB rAB mA 
//4 2 3 5 6 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<589>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 591
//mB mA mB rAB rAB mA 
//4 2 3 6 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<590>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 592
//mB mA rAB mB rAB mA 
//4 2 6 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<591>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 593
//mB rAB mA mB rAB mA 
//4 6 2 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<592>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 594
//rAB mB mA mB rAB mA 
//6 4 2 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<593>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A1, auto B)
               {
                  map(res, mul(B), A1);
               }, A2, B1);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 595
//rAB mB mA mB mA rAB 
//6 4 2 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<594>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 596
//mB rAB mA mB mA rAB 
//4 6 2 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<595>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2);
            }, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 597
//mB mA rAB mB mA rAB 
//4 2 6 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<596>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 598
//mB mA mB rAB mA rAB 
//4 2 3 6 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<597>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 599
//mB mA mB mA rAB rAB 
//4 2 3 1 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<598>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 600
//mB mA mB mA rAB rAB 
//4 2 3 1 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<599>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 601
//mB mA mA mB rAB rAB 
//4 2 1 3 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<600>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 602
//mB mA mA mB rAB rAB 
//4 2 1 3 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<601>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 603
//mB mA mA rAB mB rAB 
//4 2 1 6 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<602>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 604
//mB mA rAB mA mB rAB 
//4 2 6 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<603>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 605
//mB rAB mA mA mB rAB 
//4 6 2 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<604>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 606
//rAB mB mA mA mB rAB 
//6 4 2 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<605>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 607
//rAB mB mA mA rAB mB 
//6 4 2 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<606>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 608
//mB rAB mA mA rAB mB 
//4 6 2 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<607>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 609
//mB mA rAB mA rAB mB 
//4 2 6 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<608>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 610
//mB mA mA rAB rAB mB 
//4 2 1 6 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<609>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 611
//mB mA mA rAB rAB mB 
//4 2 1 5 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<610>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 612
//mB mA mA rAB mB rAB 
//4 2 1 5 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<611>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 613
//mB mA rAB mA mB rAB 
//4 2 5 1 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<612>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 614
//mB mA rAB mA rAB mB 
//4 2 5 1 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<613>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 615
//mB mA rAB rAB mA mB 
//4 2 5 6 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<614>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 616
//mB mA rAB rAB mA mB 
//4 2 6 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<615>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      map(res, [&](auto res, auto A3)
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
      }, A4);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 617
//mB rAB mA rAB mA mB 
//4 6 2 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<616>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 618
//rAB mB mA rAB mA mB 
//6 4 2 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<617>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 619
//rAB mB rAB mA mA mB 
//6 4 5 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<618>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 620
//mB rAB rAB mA mA mB 
//4 6 5 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<619>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 621
//mB rAB rAB mA mA mB 
//4 5 6 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<620>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 622
//mB rAB mA rAB mA mB 
//4 5 2 6 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<621>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 623
//mB rAB mA mA rAB mB 
//4 5 2 1 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<622>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 624
//mB rAB mA mA mB rAB 
//4 5 2 1 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<623>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto B3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A3, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, A4, B3);
   }, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 625
//rAB mB mA mA mB rAB 
//5 4 2 1 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<624>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 626
//rAB mB mA mA rAB mB 
//5 4 2 1 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<625>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 627
//rAB mB mA rAB mA mB 
//5 4 2 6 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<626>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         map(res, [&](auto res, auto A2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, A3);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 628
//rAB mB rAB mA mA mB 
//5 4 6 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<627>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto B2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A2, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, A3, B2);
      }, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 629
//rAB rAB mB mA mA mB 
//5 6 4 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<628>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 630
//rAB rAB mB mA mA mB 
//6 5 4 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<629>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto B1)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2);
         }, B2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 631
//rAB rAB mA mB mA mB 
//6 5 2 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<630>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 632
//rAB rAB mA mB mA mB 
//5 6 2 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<631>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 633
//rAB mA rAB mB mA mB 
//5 2 6 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<632>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 634
//rAB mA mB rAB mA mB 
//5 2 4 6 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<633>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 635
//rAB mA mB mA rAB mB 
//5 2 4 1 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<634>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 636
//rAB mA mB mA mB rAB 
//5 2 4 1 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<635>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 637
//mA rAB mB mA mB rAB 
//2 5 4 1 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<636>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 638
//mA rAB mB mA rAB mB 
//2 5 4 1 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<637>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 639
//mA rAB mB rAB mA mB 
//2 5 4 6 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<638>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 640
//mA rAB rAB mB mA mB 
//2 5 6 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<639>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 641
//mA rAB rAB mB mA mB 
//2 6 5 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<640>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 642
//rAB mA rAB mB mA mB 
//6 2 5 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<641>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, B2);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 643
//rAB mA mB rAB mA mB 
//6 2 4 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<642>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 644
//mA rAB mB rAB mA mB 
//2 6 4 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<643>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A1, auto B1)
            {
               map(res, [&](auto res, auto A)
               {
                  map(res, mul(A), B1);
               }, A1);
            }, A2, B2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 645
//mA mB rAB rAB mA mB 
//2 4 6 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<644>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 646
//mA mB rAB rAB mA mB 
//2 4 5 6 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<645>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<2>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 647
//mA mB rAB mA rAB mB 
//2 4 5 1 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<646>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 648
//mA mB rAB mA mB rAB 
//2 4 5 1 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<647>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 649
//mA mB mA rAB mB rAB 
//2 4 1 5 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<648>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 650
//mA mB mA rAB rAB mB 
//2 4 1 5 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<649>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 651
//mA mB mA rAB rAB mB 
//2 4 1 6 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<650>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 652
//mA mB rAB mA rAB mB 
//2 4 6 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<651>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 653
//mA rAB mB mA rAB mB 
//2 6 4 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<652>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 654
//rAB mA mB mA rAB mB 
//6 2 4 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<653>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 655
//rAB mA mB mA mB rAB 
//6 2 4 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<654>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 656
//mA rAB mB mA mB rAB 
//2 6 4 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<655>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto B2)
         {
            map(res, [&](auto res, auto A1)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2);
         }, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 657
//mA mB rAB mA mB rAB 
//2 4 6 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<656>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 658
//mA mB mA rAB mB rAB 
//2 4 1 6 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<657>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 659
//mA mB mA mB rAB rAB 
//2 4 1 3 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<658>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 660
//mA mB mA mB rAB rAB 
//2 4 1 3 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<659>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = flip<1>( res_ );
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto B3)
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
      }, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 661
//mA mA mB mB rAB rAB 
//2 1 4 3 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<660>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 662
//mA mA mB mB rAB rAB 
//2 1 4 3 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<661>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 663
//mA mA mB rAB mB rAB 
//2 1 4 6 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<662>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 664
//mA mA rAB mB mB rAB 
//2 1 6 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<663>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 665
//mA rAB mA mB mB rAB 
//2 6 1 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<664>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 666
//rAB mA mA mB mB rAB 
//6 2 1 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<665>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 667
//rAB mA mA mB rAB mB 
//6 2 1 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<666>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 668
//mA rAB mA mB rAB mB 
//2 6 1 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<667>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 669
//mA mA rAB mB rAB mB 
//2 1 6 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<668>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 670
//mA mA mB rAB rAB mB 
//2 1 4 6 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<669>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 671
//mA mA mB rAB rAB mB 
//2 1 4 5 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<670>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 672
//mA mA mB rAB mB rAB 
//2 1 4 5 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<671>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 673
//mA mA rAB mB mB rAB 
//2 1 5 4 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<672>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 674
//mA mA rAB mB rAB mB 
//2 1 5 4 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<673>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 675
//mA mA rAB rAB mB mB 
//2 1 5 6 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<674>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 676
//mA mA rAB rAB mB mB 
//2 1 6 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<675>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 677
//mA rAB mA rAB mB mB 
//2 6 1 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<676>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 678
//rAB mA mA rAB mB mB 
//6 2 1 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<677>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 679
//rAB mA rAB mA mB mB 
//6 2 5 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<678>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 680
//mA rAB rAB mA mB mB 
//2 6 5 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<679>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 681
//mA rAB rAB mA mB mB 
//2 5 6 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<680>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 682
//mA rAB mA rAB mB mB 
//2 5 1 6 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<681>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 683
//mA rAB mA mB rAB mB 
//2 5 1 4 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<682>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 684
//mA rAB mA mB mB rAB 
//2 5 1 4 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<683>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 685
//rAB mA mA mB mB rAB 
//5 2 1 4 3 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<684>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 686
//rAB mA mA mB rAB mB 
//5 2 1 4 6 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<685>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 687
//rAB mA mA rAB mB mB 
//5 2 1 6 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<686>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 688
//rAB mA rAB mA mB mB 
//5 2 6 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<687>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 689
//rAB rAB mA mA mB mB 
//5 6 2 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<688>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 690
//rAB rAB mA mA mB mB 
//6 5 2 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<689>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 691
//rAB rAB mA mA mB mB 
//6 5 2 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<690>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 692
//rAB rAB mA mA mB mB 
//5 6 2 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<691>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      rnz(res, t04, lift(lift(lift(lift(add)))), [&](auto res, auto A2, auto B2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2);
      }, A3, B3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t04);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 693
//rAB mA rAB mA mB mB 
//5 2 6 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<692>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 694
//rAB mA mA rAB mB mB 
//5 2 1 6 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<693>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 695
//rAB mA mA mB rAB mB 
//5 2 1 3 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<694>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 696
//rAB mA mA mB mB rAB 
//5 2 1 3 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<695>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 697
//mA rAB mA mB mB rAB 
//2 5 1 3 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<696>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 698
//mA rAB mA mB rAB mB 
//2 5 1 3 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<697>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 699
//mA rAB mA rAB mB mB 
//2 5 1 6 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<698>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 700
//mA rAB rAB mA mB mB 
//2 5 6 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<699>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 701
//mA rAB rAB mA mB mB 
//2 6 5 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<700>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 702
//rAB mA rAB mA mB mB 
//6 2 5 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<701>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t03, lift(lift(lift(add))), [&](auto res, auto A1, auto B2)
         {
            map(res, [&](auto res, auto A)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1);
         }, A2, B3);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t03);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 703
//rAB mA mA rAB mB mB 
//6 2 1 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<702>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 704
//mA rAB mA rAB mB mB 
//2 6 1 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<703>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 705
//mA mA rAB rAB mB mB 
//2 1 6 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<704>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 706
//mA mA rAB rAB mB mB 
//2 1 5 6 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<705>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            rnz(res, t02, lift(lift(add)), [&](auto res, auto A, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  map(res, mul(A), B1);
               }, B2);
            }, A1, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t02);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 707
//mA mA rAB mB rAB mB 
//2 1 5 3 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<706>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 708
//mA mA rAB mB mB rAB 
//2 1 5 3 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<707>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 709
//mA mA mB rAB mB rAB 
//2 1 3 5 4 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<708>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 710
//mA mA mB rAB rAB mB 
//2 1 3 5 6 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<709>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 711
//mA mA mB rAB rAB mB 
//2 1 3 6 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<710>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 712
//mA mA rAB mB rAB mB 
//2 1 6 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<711>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 713
//mA rAB mA mB rAB mB 
//2 6 1 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<712>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 714
//rAB mA mA mB rAB mB 
//6 2 1 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<713>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<2>( flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) ) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t01, lift(add), [&](auto res, auto A, auto B1)
               {
                  map(res, mul(A), B1);
               }, A1, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t01);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 715
//rAB mA mA mB mB rAB 
//6 2 1 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<714>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t14 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   rnz(res, t14, lift(lift(lift(lift(add)))), [&](auto res, auto A3, auto B3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3);
   }, A4, B4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t14);
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 716
//mA rAB mA mB mB rAB 
//2 6 1 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<715>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = flip<1>( subdiv<0, b>( subdiv<1, b>(A4_) ) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t13 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      rnz(res, t13, lift(lift(lift(add))), [&](auto res, auto A2, auto B3)
      {
         map(res, [&](auto res, auto A1)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2);
      }, A3, B4);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t13);
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 717
//mA mA rAB mB mB rAB 
//2 1 6 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<716>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<0>( flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t12 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         rnz(res, t12, lift(lift(add)), [&](auto res, auto A1, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, B3);
         }, A2, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t12);
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 718
//mA mA mB rAB mB rAB 
//2 1 3 6 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<717>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = flip<1>( subdiv<0, b>( subdiv<1, b>(B4_) ) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t11 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            rnz(res, t11, lift(add), [&](auto res, auto A1, auto B2)
            {
               map(res, [&](auto res, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, B2);
            }, A2, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t11);
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 719
//mA mA mB mB rAB rAB 
//2 1 3 4 6 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<718>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


//swap at indices 4 5:
//permutation: 720
//mA mA mB mB rAB rAB 
//2 1 3 4 5 6 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl6(Int<719>, T0&& res_, T1&& A4_, T2&& B4_)
{
   auto res = res_;
   auto A4 = subdiv<0, b>( subdiv<1, b>(A4_) );
   auto B4 = subdiv<0, b>( subdiv<1, b>(B4_) );
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto t10 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
   map(res, [&](auto res, auto A3)
   {
      map(res, [&](auto res, auto A2)
      {
         map(res, [&](auto res, auto B3)
         {
            map(res, [&](auto res, auto B2)
            {
               rnz(res, t10, add, [&](auto res, auto A1, auto B1)
               {
                  rnz(res, t00, add, mul, A1, B1);
               }, A2, B2);
            }, B3);
         }, B4);
      }, A3);
   }, A4);
   auto time1 = std::chrono::high_resolution_clock::now();
   Deallocate(t00);
   Deallocate(t10);
   return ms(time0, time1);
}


