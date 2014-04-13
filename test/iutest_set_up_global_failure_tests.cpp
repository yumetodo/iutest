﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_set_up_global_failure_tests.cpp
 * @brief		Environment::SetUp で失敗したときのテスト
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"

class MyEnvironment : public ::iutest::Environment
{
private:
	virtual void SetUp(void)
	{
		IUTEST_FAIL();
	}
};

IUTEST(Hoge, Test)
{
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);

	MyEnvironment* const env = new MyEnvironment();
	::iutest::AddGlobalTestEnvironment(env);

#if defined(OUTPUTXML)
	// 失敗テストを含むので xml 出力しない
	::iutest::IUTEST_FLAG(output) = NULL;
#endif
	const int ret = IUTEST_RUN_ALL_TESTS();
	if( ret == 0 ) return 1;

	printf("*** Successful ***\n");
	return 0;
}
