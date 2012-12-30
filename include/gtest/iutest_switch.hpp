//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_switch.hpp
 * @brief		gtest から iutest への切り替え用 ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2011-2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_switch_HPP_9E5FA1C8_EFB5_40a9_A3AD_971584ECAE56_
#define INCG_IRIS_iutest_switch_HPP_9E5FA1C8_EFB5_40a9_A3AD_971584ECAE56_

#if !defined(IUTEST_USE_GTEST)

#ifdef GTEST_USE_OWN_TR1_TUPLE
#  define IUTEST_USE_EXTERNAL_TR1_TUPLE	1	// gtest の tuple を使用する
#endif

//======================================================================
// include
#include "../iutest.hpp"

//======================================================================
// define

#ifdef GTEST_INCLUDE_GTEST_GTEST_H_

#undef SUCCEED
#undef FAIL
#undef ADD_FAILURE
#undef ADD_FAILURE_AT

#undef GTEST_HAS_DEATH_TEST
#undef GTEST_HAS_PARAM_TEST
#undef GTEST_HAS_COMBINE
#undef GTEST_HAS_TYPED_TEST
#undef GTEST_HAS_TYPED_TEST_P

#undef GTEST_HAS_EXCEPTIONS
#undef GTEST_HAS_RTTI
#undef GTEST_HAS_SEH

#endif

#define SUCCEED				IUTEST_SUCCEED
#define FAIL				IUTEST_FAIL
#define ADD_FAILURE			IUTEST_ADD_FAILURE
#define ADD_FAILURE_AT		IUTEST_ADD_FAILURE_AT

#define GTEST_HAS_DEATH_TEST	0
#define GTEST_HAS_PARAM_TEST	IUTEST_HAS_PARAM_TEST
#define GTEST_HAS_COMBINE		IUTEST_HAS_COMBINE
#define GTEST_HAS_TYPED_TEST	IUTEST_HAS_TYPED_TEST
#define GTEST_HAS_TYPED_TEST_P	IUTEST_HAS_TYPED_TEST_P

#define GTEST_HAS_EXCEPTIONS	IUTEST_HAS_EXCEPTIONS
#define GTEST_HAS_RTTI			IUTEST_HAS_RTTI
#define GTEST_HAS_SEH			IUTEST_HAS_SEH

#include "switch/iutest_switch_port.hpp"
#include "switch/iutest_switch_core.hpp"

#include "switch/iutest_switch_assert.hpp"
#include "switch/iutest_switch_expect.hpp"
#include "switch/iutest_switch_inform.hpp"

#include "switch/iutest_switch_eq_collections.hpp"
#include "switch/iutest_switch_package.hpp"
#include "switch/iutest_switch_peep.hpp"
#include "switch/iutest_switch_pmz.hpp"
#include "switch/iutest_switch_skip.hpp"
#include "switch/iutest_switch_throw_value.hpp"
#include "switch/iutest_switch_no_failure.hpp"

#include "switch/iutest_switch_cmphelper.hpp"

namespace iutest
{

//======================================================================
// function
inline void IUTEST_ATTRIBUTE_UNUSED_ InitGoogleTest(int* argc, char** argv)
{
	InitIrisUnitTest(argc, argv);
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitGoogleTest(int* argc, wchar_t** argv)
{
	InitIrisUnitTest(argc, argv);
}

#ifdef GMOCK_INCLUDE_GMOCK_GMOCK_H_
inline void IUTEST_ATTRIBUTE_UNUSED_ InitGoogleMock(int* argc, char** argv)
{
	testing::InitGoogleMock(argc, argv);
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitGoogleMock(int* argc, wchar_t** argv)
{
	testing::InitGoogleMock(argc, argv);
}
#endif

}

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_H_

#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
// すでに testing namespace が存在するので、define で置き換え
#  define testing	iutest
#else
// それ以外は namespace の置き換えで対応
namespace testing = iutest;
#endif

#endif

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
#  define GTEST_INCLUDE_GTEST_GTEST_H_	// 以降で、gtest が include されないようにする
#endif

#else

#ifdef INCG_IRIS_iutest_HPP_
#  if IUTEST_HAS_TUPLE
#    define GTEST_USE_OWN_TR1_TUPLE	0
#  endif
#  ifdef StaticAssertTypeEq
#	 undef StaticAssertTypeEq
#  endif
#endif

#if	defined(_MSC_VER) && _MSC_VER == 1700
#  ifndef _VARIADIC_MAX
#    define _VARIADIC_MAX	10
#  endif

#include <tuple>
namespace std {
namespace tr1
{
	using ::std::tuple;
}
}
#endif

//======================================================================
// include
#include "../iutest_ver.hpp"
#include <gtest/gtest.h>
#include "iutest_gtest_ver.hpp"

//======================================================================
// define

#ifdef INCG_IRIS_iutest_HPP_
#undef IUTEST_SUCCEED
#undef IUTEST_FAIL
#undef IUTEST_ADD_FAILURE
#undef IUTEST_ADD_FAILURE_AT

#undef IUTEST_PRED_FORMAT1_
#undef IUTEST_PRED_FORMAT2_
#undef IUTEST_PRED_FORMAT3_
#undef IUTEST_PRED_FORMAT4_
#undef IUTEST_PRED_FORMAT5_

#undef IUTEST_HAS_PARAM_TEST
#undef IUTEST_HAS_COMBINE
#undef IUTEST_HAS_VARIADIC_COMBINE
#undef IUTEST_HAS_PAIRWISE
#undef IUTEST_HAS_VARIADIC_PAIRWISE
#undef IUTEST_HAS_TYPED_TEST
#undef IUTEST_HAS_TYPED_TEST_P


#undef IUTEST_THROW_ON_ASSERT_FAILURE

#undef IUTEST_HAS_GENRAND

#undef IUTEST_HAS_VARIADIC_TEMPLATES
#undef IUTEST_HAS_VARIADIC_TEMPLATE_TEMPLATES

#undef IUTEST_HAS_EXCEPTIONS
#undef IUTEST_HAS_RTTI
#undef IUTEST_HAS_SEH

#endif

#define IUTEST_PRED_FORMAT1_	GTEST_PRED_FORMAT1_
#define IUTEST_PRED_FORMAT2_	GTEST_PRED_FORMAT2_
#define IUTEST_PRED_FORMAT3_	GTEST_PRED_FORMAT3_
#define IUTEST_PRED_FORMAT4_	GTEST_PRED_FORMAT4_
#define IUTEST_PRED_FORMAT5_	GTEST_PRED_FORMAT5_

#define IUTEST_SUCCEED			GTEST_SUCCEED
#define IUTEST_FAIL				GTEST_FAIL
#define IUTEST_ADD_FAILURE		ADD_FAILURE
#define IUTEST_ADD_FAILURE_AT	ADD_FAILURE_AT

#define IUTEST_HAS_PARAM_TEST		GTEST_HAS_PARAM_TEST
#define IUTEST_HAS_COMBINE			GTEST_HAS_COMBINE
#define IUTEST_HAS_VARIADIC_COMBINE		0
#define IUTEST_HAS_PAIRWISE				0
#define IUTEST_HAS_VARIADIC_PAIRWISE	0
#define IUTEST_HAS_TYPED_TEST		GTEST_HAS_TYPED_TEST
#define IUTEST_HAS_TYPED_TEST_P		GTEST_HAS_TYPED_TEST_P

#define IUTEST_THROW_ON_ASSERT_FAILURE	0
#define IUTEST_HAS_GENRAND				0

#define IUTEST_HAS_EXCEPTIONS		GTEST_HAS_EXCEPTIONS
#define IUTEST_HAS_RTTI				GTEST_HAS_RTTI
#define IUTEST_HAS_SEH				GTEST_HAS_SEH

#include "switch/iutest_switch_port.hpp"
#include "switch/iutest_switch_core.hpp"

#include "switch/iutest_switch_assert.hpp"
#include "switch/iutest_switch_expect.hpp"
#include "switch/iutest_switch_inform.hpp"

#include "switch/iutest_switch_eq_collections.hpp"
#include "switch/iutest_switch_package.hpp"
#include "switch/iutest_switch_peep.hpp"
#include "switch/iutest_switch_pmz.hpp"
#include "switch/iutest_switch_skip.hpp"
#include "switch/iutest_switch_throw_value.hpp"
#include "switch/iutest_switch_no_failure.hpp"

#include "switch/iutest_switch_cmphelper.hpp"


namespace testing
{

//======================================================================
// function
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, char** argv)
{
	InitGoogleTest(pargc, argv);
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, wchar_t** argv)
{
	InitGoogleTest(pargc, argv);
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, const char** argv)
{
	InitGoogleTest(pargc, const_cast<char**>(argv));
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, const wchar_t** argv)
{
	InitGoogleTest(pargc, const_cast<wchar_t**>(argv));
}

// tuple
namespace tuples
{
	using ::std::tr1::tuple;
	using ::std::tr1::tuple_size;
	using ::std::tr1::tuple_element;
	using ::std::tr1::make_tuple;
	using ::std::tr1::get;
}

using tuples::tuple;
using tuples::tuple_size;
using tuples::tuple_element;
using tuples::make_tuple;
using tuples::get;

#ifdef INCG_IRIS_iutest_HPP_
// iutest.hpp がすでにインクルードされていた場合

namespace iusupport
{
	inline AssertionResult iuMakeAssertionResult(const AssertionResult& ar) { return ar; }
	inline AssertionResult iuMakeAssertionResult(const ::iutest::AssertionResult& ar) { return AssertionResult(ar) << ar.failure_message(); }
}

// ::iutest::AssertionResult -> ::testing::AssertionResult 変換
#undef GTEST_ASSERT_
#define GTEST_ASSERT_(expression, on_failure) \
  GTEST_AMBIGUOUS_ELSE_BLOCKER_ \
  if (const ::testing::AssertionResult gtest_ar = ::testing::iusupport::iuMakeAssertionResult(expression)) \
	; \
  else \
	on_failure(gtest_ar.failure_message())

#endif

// ostream
typedef ::std::ostream	iu_ostream;

}	// end of namespace testing

#ifdef INCG_IRIS_iutest_HPP_
// すでに iutest namespace が存在するので、define で対応
#  define iutest testing
#else
namespace iutest = testing;
#endif

#include "../internal/iutest_pragma.hpp"
#include "../iutest_util.hpp"

#ifndef INCG_IRIS_iutest_HPP_
#  define INCG_IRIS_iutest_HPP_	// 以降で、iutest が include されないようにする
#endif

#endif

#endif
