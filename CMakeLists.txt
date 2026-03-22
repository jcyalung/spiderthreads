cmake_minimum_required(VERSION 4.1)
project(multi_threader)

set(CMAKE_CXX_STANDARD 20)

# 1. Tell CMake where to look for Homebrew packages on Apple Silicon
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

# Define your source files once to avoid repetition
set(SOURCE_FILES
        include/constants.h
        src/WebCrawler.cpp
        include/WebCrawler.h
        include/URLHelpers.h
        src/URLHelpers.cpp
)

add_executable(multi_threader ${SOURCE_FILES} main.cpp)

# CURL
find_package(CURL REQUIRED)
target_link_libraries(multi_threader PRIVATE CURL::libcurl)

# 2. Boost Configuration
# Note: Boost::url is part of newer Boost versions.
# Using the imported targets (Boost::headers / Boost::url) is the modern way.
find_package(Boost REQUIRED COMPONENTS url)

if(Boost_FOUND)
    message(STATUS "Boost found, version: ${Boost_VERSION}")
    # Use the modern namespace-aliased targets instead of raw variables
    target_link_libraries(multi_threader PRIVATE Boost::url)
endif()

# Sanitizers for Debugging
if (APPLE)
    target_compile_options(multi_threader PUBLIC -fsanitize=address -fno-omit-frame-pointer -g)
    target_link_options(multi_threader PUBLIC -fsanitize=address)
endif()

# 3. Fix for your tests executable
# It likely needs to link to the same libraries to work!
add_executable(tests driver.cpp ${SOURCE_FILES})
target_link_libraries(tests PRIVATE CURL::libcurl Boost::url)