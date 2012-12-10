//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_package.hpp
 * @brief		iris unit test testcase package �t�@�C��
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
#ifndef INCG_IRIS_iutest_package_HPP_F57C9B7E_7CAA_4429_BE75_FCAAEED1B220_
#define INCG_IRIS_iutest_package_HPP_F57C9B7E_7CAA_4429_BE75_FCAAEED1B220_

//======================================================================
// include
#include "internal/iutest_internal_defs.hpp"

//======================================================================
// define
/**
 * @ingroup	TESTDEF
 * @brief	�p�b�P�[�W���O��Ԃ̒�`
*/
#define IUTEST_PACKAGE(name)	IUTEST_PACKAGE_(name)

/**
 * @private
 * @{
*/

#if IUTEST_HAS_PACKAGE

#define IUTEST_CONCAT_PACKAGE_(testcase_name)					\
	iuTest_ConcatTestCaseName( iuTest_GetTestCasePackageName(	\
	static_cast<iuTest_TestCasePackage*>(NULL))					\
	, #testcase_name).c_str()

#define IUTEST_PACKAGE_(name)							\
	namespace name {									\
	class iuTest_TestCasePackage;						\
	static ::std::string IUTEST_ATTRIBUTE_UNUSED_		\
	iuTest_GetTestCasePackageName(const iuTest_TestCasePackage*) {	\
		return iuTest_GetTestCaseParentPackageName(static_cast<iuTest_TestCaseParentPackage*>(NULL)) + #name ".";	\
	}													\
	class iuTest_TestCaseParentPackage;					\
	static ::std::string IUTEST_ATTRIBUTE_UNUSED_		\
	iuTest_GetTestCaseParentPackageName(const iuTest_TestCaseParentPackage*) {				\
		return iuTest_GetTestCasePackageName(static_cast<iuTest_TestCasePackage*>(NULL));	\
	}													\
	}													\
	namespace name

#else

#define IUTEST_CONCAT_PACKAGE_(testcase_name)	#testcase_name
#define IUTEST_PACKAGE_(name)					namespace name

#endif

/**
 * @}
*/

#if IUTEST_HAS_PACKAGE

//======================================================================
// declare
class iuTest_TestCasePackage;			//!< �p�b�P�[�W���Q�Ɨp��`
class iuTest_TestCaseParentPackage;		//!< �e�p�b�P�[�W���Q�Ɨp��`

//======================================================================
// function
/**
 * @brief	�O���[�o���p�b�P�[�W���̎擾
 * @return	�p�b�P�[�W��
*/
inline ::std::string IUTEST_ATTRIBUTE_UNUSED_	iuTest_GetTestCasePackageName(const iuTest_TestCasePackage*) { return ""; }

/**
 * @brief	�e��Ԃ̃p�b�P�[�W���̎擾
 * @return	�p�b�P�[�W��
*/
inline ::std::string IUTEST_ATTRIBUTE_UNUSED_	iuTest_GetTestCaseParentPackageName(const iuTest_TestCaseParentPackage*) { return ""; }

/**
 * @brief	�e�X�g�P�[�X���Ƃ̌���
 * @return	�e�X�g�P�[�X��
*/
inline ::std::string IUTEST_ATTRIBUTE_UNUSED_	iuTest_ConcatTestCaseName(const ::std::string& package, const char* testcase_name) { return package + testcase_name; }

#endif

#endif