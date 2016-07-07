﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        logger_tests.hpp
 * @brief       logger test
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2014-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IUTEST_LOGGER_TESTS_HPP_
#define INCG_IUTEST_LOGGER_TESTS_HPP_

//======================================================================
// include
#include "iutest.hpp"

#if !defined(IUTEST_USE_GTEST)

class TestLogger : public ::iutest::detail::iuLogger
{
    ::std::string m_log;
public:
    virtual void voutput(const char* fmt, va_list va)
    {
#ifdef va_copy
        va_list va2;
        va_copy(va2, va);
        char buf[4096];
        vsprintf(buf, fmt, va2);
        va_end(va2);
        m_log += buf;
        ::iutest::detail::iuConsole::nl_voutput(fmt, va);
#else
        char buf[4096];
        vsprintf(buf, fmt, va);
        m_log += buf;
        ::iutest::detail::iuConsole::nl_output(buf);
#endif
    }
    void clear(void) { m_log.clear(); }
public:
    const char* c_str(void) const { return m_log.c_str(); }
};

#endif

#endif
