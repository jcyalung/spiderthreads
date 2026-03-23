//
// Created by Josh Yalung on 3/21/26.
//
#include <string>
#include <iostream>
#include <type_traits>

#include <stdexcept>
#ifndef MULTI_THREADER_WEBCRAWLER_H
#define MULTI_THREADER_WEBCRAWLER_H


class WebCrawler {
    std::string startingURL;
    unsigned int numURLs = 100;
    std::ostream history_log;
    std::ostream log;
    unsigned int delay;
    unsigned int threads;
public:
    WebCrawler(
        std::string&  startingURL,
        unsigned int& numURLs,
        std::ostream& history_log,
        std::ostream& log,
        unsigned int& delay,
        unsigned int& threads);

    virtual ~WebCrawler();
};


#endif //MULTI_THREADER_WEBCRAWLER_H