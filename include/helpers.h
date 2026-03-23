//
// Created by Josh Yalung on 3/20/26.
//

#ifndef MULTI_THREADER_CONSTANTS_H
#define MULTI_THREADER_CONSTANTS_H
#include <regex>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

#define USAGE_STATEMENT "Usage:\n"\
"  SpiderThread -s <STARTING_URL> -n <NUMBER_OF_WEBSITES> [OPTIONS]\n"\
"  SpiderThread -c <CONTINUE_LOG_FILE> [OPTIONS]\n\n"
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

class RETURN_EXCEPTION : public std::exception {
    public:
        int code;
        RETURN_EXCEPTION(int code) { this->code = code; }
};

#endif //MULTI_THREADER_CONSTANTS_H