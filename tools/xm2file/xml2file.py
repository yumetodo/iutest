#!/usr/bin/env python
#
# xml2file.py
#
# Copyright (C) 2019, Takazumi Shirayanagi
# This software is released under the new BSD License,
# see LICENSE
#

import argparse
import os
import re
import codecs
import xml.etree.ElementTree as ET

from argparse import ArgumentParser


# EvalIntAction
class EvalIntAction(argparse.Action):
    def __call__(self, parser, namespace, values, options_string=None):
        setattr(namespace, self.dest, int(eval(values[0])))


# command line option
def parse_command_line():
    parser = ArgumentParser()
    parser.add_argument(
        '-v',
        '--version',
        action='version',
        version=u'%(prog)s version 0.1'
    )
    parser.add_argument(
        '-o',
        '--output',
        default=None,
        help='output file path.'
    )
    parser.add_argument(
        '--encoding',
        default=None,
        help='output file encoding.'
    )
    parser.add_argument(
        'file',
        metavar='FILE',
        nargs='+',
        help='test result xml files'
    )
    options = parser.parse_args()
    return options

cmdline_options = None


def fopen(path):
    f = codecs.open(os.path.join(cmdline_options.ouput, path), 'w', cmdline_options.encoding)
    return f


def make_path(filename, testsuites, testsuite, testcase):
    # root_name = testsuites.attrib['name']
    root_name = filename
    suite_name = testsuite.attrib['name']
    case_name = testsuite.attrib['name']
    return os.path.join(os.path.join(root_name, suite_name), case_name)


def xml2file(path):
    tree = ET.parse(path)
    root = tree.getroot()
    testsuites = root

    filename = os.path.split(os.path.basename(path))[0]

    print(testsuites.tag)
    for attr in testsuites.attrib:
        print(attr)
    for testsuite in testsuites:
        print(testsuite.tag)
        for attr in testsuite.attrib:
            print(attr)
        for testcase in testsuite:
            print(testcase.tag, testcase.text)
            for attr in testcase.attrib:
                print(attr)

def main():
    global cmdline_options
    cmdline_options = parse_command_line()
    for path in cmdline_options.file:
        xml2file(path)

if __name__ == '__main__':
    main()
