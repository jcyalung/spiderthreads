//
// Created by Josh Yalung on 3/22/26.
//

#ifndef SPIDERTHREAD_PARSEHELPERS_H
#define SPIDERTHREAD_PARSEHELPERS_H
#include <iostream>
#include <regex>
#include <boost/url/parse.hpp>
#include <boost/program_options.hpp>
#include <iomanip>
#include <string>
const int COL_WIDTH = 20;
const std::regex FILE_REGEX{R"(.*\.(txt|log)$)"};
using std::cout;
using std::cerr;
using std::endl;
namespace po = boost::program_options;

void print_args(const po::variables_map& vm);
po::variables_map parse_args(int argc, char* argv[]);
bool valid_options(const po::variables_map& vm);





#endif //SPIDERTHREAD_PARSEHELPERS_H