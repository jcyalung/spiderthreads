//
// Created by Josh Yalung on 3/20/26.
//

#ifndef MULTI_THREADER_CONSTANTS_H
#define MULTI_THREADER_CONSTANTS_H
#include <regex>
#include <boost/program_options/options_description.hpp>

#define USAGE_STATEMENT "Usage:\n"\
"  SpiderThread -s <STARTING_URL> -n <NUMBER_OF_WEBSITES> [OPTIONS]\n"\
"  SpiderThread -c <CONTINUE_LOG_FILE> [OPTIONS]\n\n"
/*
"Modes (Mutually Exclusive):\n"\
"  -s <STARTING_URL>        URL to start crawling from. (Requires -n)\n"\
"  -n <NUMBER_OF_WEBSITES>  Number of websites to crawl. Default: 100. (Requires -s)\n"\
"      -- OR --\n"\
"  -c <CONTINUE_LOG_FILE>   Resume crawl from a previous state. Writes output\n"\
"                           (visited count, next URL, remaining count, and visited URLs)\n"\
"                           to this file. If omitted, outputs to stdout.\n\n"\
"Optional Flags:\n"\
"  -t <THREADS>             Number of concurrent threads to use. Default: 1.\n"\
"  -d <DELAY>               Delay in milliseconds to introduce politeness. Default: 300.\n"\
"  -h <HISTORY_FILE>        File to write the list of all websites visited.\n"\
"  -l <LOG_FILE>            Log file to save runtime progress and general logging.\n\n"\
"Examples:\n"\
"  Start a new crawl:\n"\
"    ./SpiderThread -s https://example.com -n 500 -t 4 -d 500 -l run.log\n"\
"  Resume a previous crawl:\n"\
"    ./SpiderThread -c state_backup.log -t 4 -h visited.txt\n\n" */
const int COL_WIDTH = 20;
const std::regex PATTERN(
    R"(.*\.(css|js|bmp|gif|jpe?g|ico)"
    R"(|png|tiff?|mid|mp2|mp3|mp4)"
    R"(|wav|avi|mov|mpeg|ram|m4v|mkv|ogg|ogv|pdf)"
    R"(|ps|eps|tex|ppt|pptx|doc|docx|xls|xlsx|names)"
    R"(|data|dat|exe|bz2|tar|msi|bin|7z|psd|dmg|iso)"
    R"(|epub|dll|cnf|tgz|sha1)"
    R"(|thmx|mso|arff|rtf|jar|csv)"
    R"(|rm|smil|wmv|swf|wma|zip|rar|gz)$)"
);



#endif //MULTI_THREADER_CONSTANTS_H