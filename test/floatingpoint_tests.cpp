﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        floatingpoint_tests.cpp
 * @brief       float/double test
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2017, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include <cmath>
#include "iutest.hpp"

#if !defined(IUTEST_USE_GTEST)

#if IUTEST_HAS_TYPED_TEST

namespace floatingpoint_test
{

template<typename T>
class FloatingpointTest : public ::iutest::Test
{
public:
    typedef ::iutest::floating_point<T> ftype;

    static T ONE;
    static T ZERO;
};
template<typename T>
T FloatingpointTest<T>::ONE = (T)1;
template<typename T>
T FloatingpointTest<T>::ZERO = (T)0;

typedef ::iutest::Types<float, double> FloatingpointTestTypes;
IUTEST_TYPED_TEST_CASE(FloatingpointTest, FloatingpointTestTypes);

IUTEST_TYPED_TEST(FloatingpointTest, PINF)
{
    typedef typename TestFixture::ftype FloatType;
    TypeParam a=TestFixture::ONE;
    TypeParam b=TestFixture::ZERO;

    IUTEST_EXPECT_EQ(FloatType(a/b), TestFixture::ftype::PINF());
}

IUTEST_TYPED_TEST(FloatingpointTest, NINF)
{
    typedef typename TestFixture::ftype FloatType;
    TypeParam b=TestFixture::ZERO;

    IUTEST_EXPECT_EQ(FloatType(log(b)), TestFixture::ftype::NINF());
}

// MinGW-w64 sqrt bug
// https://sourceforge.net/p/mingw/bugs/2337/
#if !defined(__MINGW64__)
IUTEST_TYPED_TEST(FloatingpointTest, NQNAN)
{
    typedef typename TestFixture::ftype FloatType;
    TypeParam a=TestFixture::ONE;

    IUTEST_EXPECT_EQ(FloatType(sqrt(-a)), TestFixture::ftype::NQNAN());
}
#endif

}   // end of namespace floatingpoint_test

#endif

#endif
