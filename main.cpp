#include <iostream>
#include <string>
#include <iomanip>
#include "include/helpers.h"
#include <boost/program_options.hpp>
using std::cout;
using std::cerr;
using std::endl;
namespace po = boost::program_options;

int main(int argc, char* argv[]) {

    // TODO: parse args
    po::options_description spider_thread_options(USAGE_STATEMENT);
    spider_thread_options.add_options()
    ("help", "HELP print this message")
    ("continue,c", po::value<std::string>(), "CONTINUE_LOG_FILE to resume from")
    ("history_log,h", po::value<std::string>()->required(), "HISTORY_FILE to write websites visited")
    ("threads,t", po::value<int>()->default_value(1), "THREADS maximum number of threads")
    ("number,n",po::value<int>()->default_value(100), "NUMBER_OF_WEBSITES max number of websites to crawl")
    ("start,s",po::value<std::string>(), "STARTING URL url to start from")
    ("delay,d", po::value<int>()->default_value(300), "DELAY delay in ms for politeness")
    ("log,l", po::value<std::string>()->required(), "LOG_FILE to save PROGRESS");
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, spider_thread_options), vm);
        po::notify(vm);
        if(vm.contains("help")) {
            std::cout << spider_thread_options << std::endl;
            return 0;
        }

        const bool c_flag = vm.contains("continue"), s_flag = vm.contains("start"), n_flag = !vm["number"].defaulted();

        if(c_flag) {
            if(s_flag || n_flag) {
                cerr << "-c flag is mutually exclusive from -s AND -n" << endl;
                cerr << spider_thread_options << endl;
                return 1;
            }
        }
        else {
            if(!s_flag) {
                cerr << "-s flag is required for a new crawl" << endl;
                cerr << spider_thread_options << endl;
                return 1;
            }
        }
    }
    catch (std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        cerr << spider_thread_options << endl;
        return 1;
    }
    catch(...) {
        cerr << "Unknown error occurred" << endl;
        return 1;
    }

    // print out args
    cout << "Web crawler initialized with args:" << endl;
    if(vm.contains("continue")) {
        cout << std::left << std::setw(COL_WIDTH) << "continue" <<  vm["continue"].as<std::string>() << endl;
    }
    if(vm.contains("history_log")) {
        cout << std::left << std::setw(COL_WIDTH) << "history_log" <<  vm["history_log"].as<std::string>() << endl;
    }
    if(vm.contains("threads")) {
        cout << std::left << std::setw(COL_WIDTH) << "threads" <<  vm["threads"].as<int>() << endl;
    }
    if(vm.contains("number")) {
        cout << std::left << std::setw(COL_WIDTH) << "number" <<  vm["number"].as<int>() << endl;
    }
    if(vm.contains("start")) {
        cout << std::left << std::setw(COL_WIDTH) << "start" <<  vm["start"].as<std::string>() << endl;
    }
    if(vm.contains("delay")) {
        cout << std::left << std::setw(COL_WIDTH) << "delay" <<  vm["delay"].as<int>() << endl;
    }
    if(vm.contains("log")) {
        cout << std::left << std::setw(COL_WIDTH) << "log" <<  vm["log"].as<std::string>() << endl;
    }
    return 0;
}
