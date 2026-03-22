//
// Created by Josh Yalung on 3/20/26.
//

#ifndef MULTI_THREADER_CONSTANTS_H
#define MULTI_THREADER_CONSTANTS_H
#define PORT 8000
#define ADDRESS "127.0.0.1"
#include <regex>
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