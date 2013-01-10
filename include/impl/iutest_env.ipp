//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_env.ipp
 * @brief		iris unit test �� �t�@�C��
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
#ifndef INCG_IRIS_iutest_env_IPP_F4017EAB_6CA3_4e6e_8983_059393DADD04_
#define INCG_IRIS_iutest_env_IPP_F4017EAB_6CA3_4e6e_8983_059393DADD04_

//======================================================================
// include
#include "../iutest_env.hpp"

namespace iutest
{

IUTEST_IPP_INLINE bool TestEnv::ParseCommandLineElemA(const char* str)
{
	bool find = false;
	if( *str == '-' )
	{
		find = true;
		++str;
		if( *str == '-' )
		{
			++str;
			bool iuoption = false;
			{
				const char* const base_str = str;
				if( *str == 'g' ) 
				{
					++str;
					iuoption = true;
				}
				if(*str == 'i' && *(str+1) == 'u' )
				{
					str += 2;
					iuoption = true;
				}
				const char option_prefix[] = "test_";
				for( int i=0, size=sizeof(option_prefix)/sizeof(option_prefix[0])-1; i < size; ++i, ++str )
				{
					if( *str != option_prefix[i] )
					{
						iuoption = false;
						str = base_str;
						break;
					}
				}
			}
			if( iuoption )
			{
				// --iutest_*
				if( strstr(str, "output") == str )
				{
					find = ParseOutputOption(ParseOptionSettingStr(str));
				}
				else if( detail::IsStringEqual(str, "list_tests") )
				{
					TestFlag::SetFlag(TestFlag::SHOW_TESTS_LIST);
				}
				else if( strstr(str, "color") == str )
				{
					find = ParseColorOption(ParseOptionSettingStr(str));
				}
				else if( detail::IsStringEqual(str, "shuffle") )
				{
					TestFlag::SetFlag(TestFlag::SHUFFLE_TESTS);
				}
				else if( strstr(str, "random_seed") == str )
				{
					const char* opt = ParseOptionSettingStr(str);
					if( opt != NULL )
					{
						char* end = NULL;
						long seed = strtol(opt, &end, 0);
						init_random(static_cast<unsigned int>(seed));
					}
					else
					{
						find = false;
					}
				}
				else if( detail::IsStringEqual(str, "also_run_disabled_tests") )
				{
					TestFlag::SetFlag(TestFlag::RUN_DISABLED_TESTS);
				}
				else if( strstr(str, "break_on_failure") == str )
				{
					find = ParseYesNoFlagOption(str, TestFlag::BREAK_ON_FAILURE, 1);
				}
				else if( strstr(str, "catch_exceptions") == str )
				{
					find = ParseYesNoFlagOption(str, TestFlag::CATCH_EXCEPTION, -1);
				}
				else if( strstr(str, "throw_on_failure") == str )
				{
					find = ParseYesNoFlagOption(str, TestFlag::THROW_ON_FAILURE, 1);
				}
				else if( strstr(str, "print_time") == str )
				{
					find = ParseYesNoFlagOption(str, TestFlag::PRINT_TIME, -1);
				}
				else if( strstr(str, "repeat") == str )
				{
					const char* opt = ParseOptionSettingStr(str);
					if( opt != NULL )
					{
						char* end = NULL;
						long count = strtol(opt, &end, 0);
						set_repeat_count(static_cast<int>(count));
					}
					else
					{
						find = false;
					}
				}
				else if( strstr(str, "filter") == str )
				{
					const char* opt = ParseOptionSettingStr(str);
					if( opt != NULL )
					{
						set_test_filter(opt);
					}
				}
				else
				{
					find = false;
				}
				if( !find )
				{
					// �Y������I�v�V�������Ȃ��ꍇ�̓w���v�\��
					TestFlag::SetFlag(TestFlag::SHOW_HELP);
				}
			}
			else if( detail::IsStringEqual(str, "help") )
			{
				TestFlag::SetFlag(TestFlag::SHOW_HELP);
			}
			else if( detail::IsStringEqual(str, "version") )
			{
				TestFlag::SetFlag(TestFlag::SHOW_VERSION);
			}
			else if( detail::IsStringEqual(str, "feature") )
			{
				TestFlag::SetFlag(TestFlag::SHOW_FEATURE);
			}
			else
			{
				find = false;
			}
		}
		else
		{
			if( detail::IsStringEqual(str, "v") )
			{
				TestFlag::SetFlag(TestFlag::SHOW_VERSION);
			}
			else if( detail::IsStringEqual(str, "h")
				|| detail::IsStringEqual(str, "?") )
			{
				TestFlag::SetFlag(TestFlag::SHOW_HELP);
			}
			else
			{
				find = false;
			}
		}
	}
	return find;
}

IUTEST_IPP_INLINE void TestEnv::LoadEnviromentVariable(void)
{
	{
		int var = 0;
		if( detail::GetEnvironmentInt("IUTEST_ALSO_RUN_DISABLED_TESTS", var) )
		{
			TestFlag::SetFlag(TestFlag::RUN_DISABLED_TESTS
				, var ? TestFlag::MASK : ~(TestFlag::RUN_DISABLED_TESTS) );
		}
		if( detail::GetEnvironmentInt("IUTEST_SHUFFLE", var) )
		{
			TestFlag::SetFlag(TestFlag::SHUFFLE_TESTS
				, var ? TestFlag::MASK : ~(TestFlag::SHUFFLE_TESTS) );
		}
		if( detail::GetEnvironmentInt("IUTEST_RANDOM_SEED", var) )
		{
			init_random((unsigned int)var);
		}
		if( detail::GetEnvironmentInt("IUTEST_CATCH_EXCEPTIONS", var) )
		{
			TestFlag::SetFlag(TestFlag::CATCH_EXCEPTION
				, var ? TestFlag::MASK : ~(TestFlag::CATCH_EXCEPTION) );
		}
		if( detail::GetEnvironmentInt("IUTEST_BREAK_ON_FAILURE", var) )
		{
			TestFlag::SetFlag(TestFlag::BREAK_ON_FAILURE
				, var ? TestFlag::MASK : ~(TestFlag::BREAK_ON_FAILURE) );
		}
		if( detail::GetEnvironmentInt("IUTEST_THROW_ON_FAILURE", var) )
		{
			TestFlag::SetFlag(TestFlag::THROW_ON_FAILURE
				, var ? TestFlag::MASK : ~(TestFlag::THROW_ON_FAILURE) );
		}
		if( detail::GetEnvironmentInt("IUTEST_PRINT_TIME", var) )
		{
			TestFlag::SetFlag(TestFlag::PRINT_TIME
				, var ? TestFlag::MASK : ~(TestFlag::PRINT_TIME) );
		}
		if( detail::GetEnvironmentInt("IUTEST_REPEAT", var) )
		{
			set_repeat_count(var);
		}
	}
	{
		char var[128] = {0};
		if( detail::GetEnvironmentVariable("IUTEST_COLOR", var) )
		{
			ParseColorOption(var);
		}
	}
	{
		char path[260+32] = {0};
		if( detail::GetEnvironmentVariable("IUTEST_OUTPUT", path) )
		{
			ParseOutputOption(path);
		}
		if( detail::GetEnvironmentVariable("IUTEST_FILTER", path) )
		{
			set_test_filter(path);
		}
	}
}

IUTEST_IPP_INLINE void	TestEnv::SetUp(void)
{
	unsigned int seed = get_random_seed();
	if( seed == 0 )
	{
		seed = detail::GetIndefiniteValue();
	}
	get_vars().m_current_random_seed = seed;
	genrand().init(seed);
}

IUTEST_IPP_INLINE 	bool TestEnv::ParseColorOption(const char* option)
{
	if( option == NULL ) return false;

	if( IsYes(option) )
	{
		TestFlag::SetFlag(TestFlag::CONSOLE_COLOR_ON, ~TestFlag::CONSOLE_COLOR_OFF);
	}
	else if( IsNo(option) )
	{
		TestFlag::SetFlag(TestFlag::CONSOLE_COLOR_OFF, ~TestFlag::CONSOLE_COLOR_ON);
	}
	else if( detail::IsStringCaseEqual(option, "auto") )
	{
		// auto
		TestFlag::SetFlag(0, ~(TestFlag::CONSOLE_COLOR_ON|TestFlag::CONSOLE_COLOR_OFF));
	}
	else if( detail::IsStringCaseEqual(option, "ansi") )
	{
		// ansi
		TestFlag::SetFlag(TestFlag::CONSOLE_COLOR_ON|TestFlag::CONSOLE_COLOR_ANSI, ~TestFlag::CONSOLE_COLOR_OFF);
	}
	else 
	{
		return false;
	}
	return true;
}

IUTEST_IPP_INLINE bool	TestEnv::ParseOutputOption(const char* option)
{
	if( option == NULL ) return false;
	if( strstr(option, "xml") != NULL )
	{
		TestFlag::SetFlag(TestFlag::OUTPUT_XML_REPORT);
	}
	else
	{
		return false;
	}
	const char* file = strchr(option+3, ':');
	if( file != NULL )
	{
		get_vars().m_report_file = file+1;
	}
	return true;
}

}	// end of namespace iutest

#endif