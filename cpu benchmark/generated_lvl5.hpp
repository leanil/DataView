//permutation: 1
//mA mA mB mB rAB 
//1 2 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<0>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 2
//mA mA mB rAB mB 
//1 2 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<1>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 3
//mA mA rAB mB mB 
//1 2 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<2>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 4
//mA rAB mA mB mB 
//1 5 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<3>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 5
//rAB mA mA mB mB 
//5 1 2 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<4>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 6
//rAB mA mA mB mB 
//5 1 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<5>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 7
//mA rAB mA mB mB 
//1 5 2 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<6>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 8
//mA mA rAB mB mB 
//1 2 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<7>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 9
//mA mA mB rAB mB 
//1 2 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<8>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 10
//mA mA mB mB rAB 
//1 2 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<9>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 11
//mA mB mA mB rAB 
//1 4 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<10>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 12
//mA mB mA rAB mB 
//1 4 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<11>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 13
//mA mB rAB mA mB 
//1 4 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<12>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 14
//mA rAB mB mA mB 
//1 5 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<13>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 15
//rAB mA mB mA mB 
//5 1 4 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<14>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 16
//rAB mB mA mA mB 
//5 4 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<15>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 17
//mB rAB mA mA mB 
//4 5 1 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<16>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 18
//mB mA rAB mA mB 
//4 1 5 2 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<17>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 19
//mB mA mA rAB mB 
//4 1 2 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<18>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 20
//mB mA mA mB rAB 
//4 1 2 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<19>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 21
//mB mA mB mA rAB 
//4 1 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<20>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 22
//mB mA mB rAB mA 
//4 1 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<21>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 23
//mB mA rAB mB mA 
//4 1 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<22>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 24
//mB rAB mA mB mA 
//4 5 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<23>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 25
//rAB mB mA mB mA 
//5 4 1 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<24>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 26
//rAB mA mB mB mA 
//5 1 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<25>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 27
//mA rAB mB mB mA 
//1 5 4 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<26>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 28
//mA mB rAB mB mA 
//1 4 5 3 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<27>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 29
//mA mB mB rAB mA 
//1 4 3 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<28>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 30
//mA mB mB mA rAB 
//1 4 3 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<29>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 31
//mA mB mB mA rAB 
//1 3 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<30>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 32
//mA mB mB rAB mA 
//1 3 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<31>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 33
//mA mB rAB mB mA 
//1 3 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<32>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 34
//mA rAB mB mB mA 
//1 5 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<33>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 35
//rAB mA mB mB mA 
//5 1 3 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<34>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 36
//rAB mA mB mA mB 
//5 1 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<35>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 37
//mA rAB mB mA mB 
//1 5 3 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<36>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 38
//mA mB rAB mA mB 
//1 3 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<37>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 39
//mA mB mA rAB mB 
//1 3 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<38>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 40
//mA mB mA mB rAB 
//1 3 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<39>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 41
//mB mA mA mB rAB 
//3 1 2 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<40>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 42
//mB mA mA rAB mB 
//3 1 2 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<41>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 43
//mB mA rAB mA mB 
//3 1 5 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<42>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 44
//mB rAB mA mA mB 
//3 5 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<43>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 45
//rAB mB mA mA mB 
//5 3 1 2 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<44>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 46
//rAB mB mA mB mA 
//5 3 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<45>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 47
//mB rAB mA mB mA 
//3 5 1 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<46>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 48
//mB mA rAB mB mA 
//3 1 5 4 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<47>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 49
//mB mA mB rAB mA 
//3 1 4 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<48>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 50
//mB mA mB mA rAB 
//3 1 4 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<49>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 51
//mB mB mA mA rAB 
//3 4 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<50>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 52
//mB mB mA rAB mA 
//3 4 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<51>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 53
//mB mB rAB mA mA 
//3 4 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<52>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = subdiv<0, b>(B3_);
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 54
//mB rAB mB mA mA 
//3 5 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<53>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 55
//rAB mB mB mA mA 
//5 3 4 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<54>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 56
//rAB mB mB mA mA 
//5 4 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<55>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 57
//mB rAB mB mA mA 
//4 5 3 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<56>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 58
//mB mB rAB mA mA 
//4 3 5 1 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<57>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = subdiv<0, b>(B3_);
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 59
//mB mB mA rAB mA 
//4 3 1 5 2 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<58>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 60
//mB mB mA mA rAB 
//4 3 1 2 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<59>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 61
//mB mB mA mA rAB 
//4 3 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<60>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 62
//mB mB mA rAB mA 
//4 3 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<61>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 63
//mB mB rAB mA mA 
//4 3 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<62>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = subdiv<0, b>(B3_);
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 64
//mB rAB mB mA mA 
//4 5 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<63>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 65
//rAB mB mB mA mA 
//5 4 3 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<64>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 66
//rAB mB mB mA mA 
//5 3 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<65>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 67
//mB rAB mB mA mA 
//3 5 4 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<66>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 68
//mB mB rAB mA mA 
//3 4 5 2 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<67>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = subdiv<0, b>(B3_);
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 69
//mB mB mA rAB mA 
//3 4 2 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<68>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 70
//mB mB mA mA rAB 
//3 4 2 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<69>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 71
//mB mA mB mA rAB 
//3 2 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<70>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 72
//mB mA mB rAB mA 
//3 2 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<71>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 73
//mB mA rAB mB mA 
//3 2 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<72>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 74
//mB rAB mA mB mA 
//3 5 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<73>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 75
//rAB mB mA mB mA 
//5 3 2 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<74>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 76
//rAB mB mA mA mB 
//5 3 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<75>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 77
//mB rAB mA mA mB 
//3 5 2 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<76>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 78
//mB mA rAB mA mB 
//3 2 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<77>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 79
//mB mA mA rAB mB 
//3 2 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<78>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 80
//mB mA mA mB rAB 
//3 2 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<79>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 81
//mA mB mA mB rAB 
//2 3 1 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<80>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 82
//mA mB mA rAB mB 
//2 3 1 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<81>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 83
//mA mB rAB mA mB 
//2 3 5 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<82>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 84
//mA rAB mB mA mB 
//2 5 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<83>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 85
//rAB mA mB mA mB 
//5 2 3 1 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<84>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 86
//rAB mA mB mB mA 
//5 2 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<85>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 87
//mA rAB mB mB mA 
//2 5 3 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<86>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 88
//mA mB rAB mB mA 
//2 3 5 4 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<87>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 89
//mA mB mB rAB mA 
//2 3 4 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<88>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 90
//mA mB mB mA rAB 
//2 3 4 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<89>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 91
//mA mB mB mA rAB 
//2 4 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<90>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 92
//mA mB mB rAB mA 
//2 4 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<91>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 93
//mA mB rAB mB mA 
//2 4 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<92>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 94
//mA rAB mB mB mA 
//2 5 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<93>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 95
//rAB mA mB mB mA 
//5 2 4 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<94>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<2>( flip<0>( flip<1>( res_ ) ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 96
//rAB mB mA mB mA 
//5 4 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<95>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 97
//mB rAB mA mB mA 
//4 5 2 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<96>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 98
//mB mA rAB mB mA 
//4 2 5 3 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<97>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 99
//mB mA mB rAB mA 
//4 2 3 5 1 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<98>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = subdiv<0, b>(B3_);
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 100
//mB mA mB mA rAB 
//4 2 3 1 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<99>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<2>( flip<0>( flip<1>( res_ ) ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 101
//mB mA mA mB rAB 
//4 2 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<100>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 102
//mB mA mA rAB mB 
//4 2 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<101>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 103
//mB mA rAB mA mB 
//4 2 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<102>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 104
//mB rAB mA mA mB 
//4 5 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<103>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 105
//rAB mB mA mA mB 
//5 4 2 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<104>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<0>( flip<1>( res_ ) );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 106
//rAB mA mB mA mB 
//5 2 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<105>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 107
//mA rAB mB mA mB 
//2 5 4 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<106>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 108
//mA mB rAB mA mB 
//2 4 5 1 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<107>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 109
//mA mB mA rAB mB 
//2 4 1 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<108>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 110
//mA mB mA mB rAB 
//2 4 1 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<109>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = flip<1>( res_ );
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 111
//mA mA mB mB rAB 
//2 1 4 3 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<110>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 112
//mA mA mB rAB mB 
//2 1 4 5 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<111>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 113
//mA mA rAB mB mB 
//2 1 5 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<112>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 114
//mA rAB mA mB mB 
//2 5 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<113>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 115
//rAB mA mA mB mB 
//5 2 1 4 3 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<114>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 116
//rAB mA mA mB mB 
//5 2 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<115>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<0>( flip<1>( subdiv<0, b>(A3_) ) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t04 = AllocateViewSimilarToButDropFrontDimensionsUpTo<4>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 0 1:
//permutation: 117
//mA rAB mA mB mB 
//2 5 1 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<116>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = flip<1>( subdiv<0, b>(A3_) );
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t03 = AllocateViewSimilarToButDropFrontDimensionsUpTo<3>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 1 2:
//permutation: 118
//mA mA rAB mB mB 
//2 1 5 3 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<117>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<0>( flip<1>( subdiv<0, b>(B3_) ) );
   auto t02 = AllocateViewSimilarToButDropFrontDimensionsUpTo<2>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 2 3:
//permutation: 119
//mA mA mB rAB mB 
//2 1 3 5 4 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<118>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = flip<1>( subdiv<0, b>(B3_) );
   auto t01 = AllocateViewSimilarToButDropFrontDimensionsUpTo<1>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


//swap at indices 3 4:
//permutation: 120
//mA mA mB mB rAB 
//2 1 3 4 5 
template<int b, typename T0, typename T1, typename T2>
auto kernel_lvl5(Int<119>, T0&& res_, T1&& A3_, T2&& B3_)
{
   auto res = res_;
   auto A3 = subdiv<0, b>(A3_);
   auto B3 = subdiv<0, b>(B3_);
   auto t00 = AllocateViewSimilarToButDropFrontDimensionsUpTo<0>(res);
   auto time0 = std::chrono::high_resolution_clock::now();
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
   auto time1 = std::chrono::high_resolution_clock::now();
   return ms(time0, time1);
}


