/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2011 06:34:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */
#include <iostream>

#include <boost/regex.hpp>

int main( int argc, char* argv[] )
{
    char *buf = "This is boost::regex example";

    boost::regex exampleregex( "boost::regex" );
    boost::cmatch result;

    if( boost::regex_search( buf, result, exampleregex ) )
    {
        std::cout << result.str() << std::endl;
    }

    return 0;
}

