cmake_minimum_required(VERSION 4.1)
project(SpiderThread)

set(CMAKE_CXX_STANDARD 20)

# 1. Tell CMake where to look for Homebrew packages on Apple Silicon
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

# Define your source files once to avoid repetition
set(SOURCE_FILES
        include/helpers.h
        src/WebCrawler.cpp
        include/WebCrawler.h
        include/URLHelpers.h
        src/URLHelpers.cpp
        include/parseHelpers.h
        src/parseHelpers.cpp
)

# CURL
find_package(CURL REQUIRED)

# 2. Boost Configuration
# Note: Boost::url is part of newer Boost versions.
# Using the imported targets (Boost::headers / Boost::url) is the modern way.
find_package(Boost REQUIRED COMPONENTS url program_options)


# edit this if needed
set(COMMON_LIBS
    CURL::libcurl
    Boost::url
    Boost::program_options
)

function(apply_settings TARGET_NAME)
    target_link_libraries(${TARGET_NAME} PRIVATE ${COMMON_LIBS})
    # Sanitizers for Debugging
    if (APPLE)
        target_compile_options(${TARGET_NAME} PUBLIC -fsanitize=address -fno-omit-frame-pointer -g)
        target_link_options(${TARGET_NAME} PUBLIC -fsanitize=address)
    endif()
endfunction()

add_executable(SpiderThread main.cpp ${SOURCE_FILES})
apply_settings(SpiderThread)

add_executable(tests driver.cpp ${SOURCE_FILES})
apply_settings(tests)