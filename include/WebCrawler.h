//
// Created by Josh Yalung on 3/21/26.
//
#include <string>
#include <iostream>
#include <type_traits>
#include <cassert>

#include <stdexcept>
#ifndef MULTI_THREADER_WEBCRAWLER_H
#define MULTI_THREADER_WEBCRAWLER_H


class WebCrawler {
private:
    std::string startingURL;
    unsigned int numURLs = 100;
public:
    WebCrawler() {
        throw std::runtime_error("Must define starting URL");
    }
    WebCrawler(std::string startingURL) {
        static_assert(std::is_same_v<decltype(startingURL), std::string>, "startingURL must be of type string");
        this->startingURL = startingURL;
    }
    WebCrawler(std::string startingURL, unsigned int numURLs) {
        static_assert(std::is_same_v<decltype(startingURL), std::string>, "startingURL must be of type string");
        static_assert(std::is_same_v<decltype(numURLs), unsigned int>, "numURLs must be of type unsigned int");
        this->startingURL = startingURL;
        this->numURLs = numURLs;
    }


};


#endif //MULTI_THREADER_WEBCRAWLER_H