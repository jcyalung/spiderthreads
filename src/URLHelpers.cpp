//
// Created by Josh Yalung on 3/21/26.
//

#include "../include/URLHelpers.h"
#include "../include/constants.h"
#include <regex>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/system/result.hpp>
#include <boost/url/parse.hpp>
#include <boost/url/url_view.hpp>

bool is_valid_URL(const std::string& url) {
    if(url.empty()) { return false; }
    auto result = boost::urls::parse_uri(url);
    if(result.has_error()) {
        return false;
    }
    auto const& boost_url = result.value();
    if(boost_url.scheme() != "http" && boost_url.scheme() != "https") { return false; }
    std::string path = boost_url.path();
    boost::algorithm::to_lower(path);
    return !std::regex_match(path, PATTERN);
}
