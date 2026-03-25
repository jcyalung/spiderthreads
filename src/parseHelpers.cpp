//
// Created by Josh Yalung on 3/22/26.
//
#include "../include/parseHelpers.h"
#include "../include/helpers.h"
void print_args(const po::variables_map& vm) {
    cout << "Web crawler initialized with args:" << endl;
    if(vm.contains("continue")) {
        cout << std::left << std::setw(COL_WIDTH) << "continue:"
             <<  std::format("\033[32m{}\033[0m",vm["continue"].as<std::string>()) << endl;
    }
    if(vm.contains("history_log")) {
        cout << std::left << std::setw(COL_WIDTH) << "history_log:"
             <<  std::format("\033[32m{}\033[0m",vm["history_log"].as<std::string>()) << endl;
    }
    if(vm.contains("threads")) {
        cout << std::left << std::setw(COL_WIDTH) << "threads:"
             <<  std::format("\033[32m{}\033[0m",vm["threads"].as<int>()) << endl;
    }
    if(vm.contains("n_websites")) {
        cout << std::left << std::setw(COL_WIDTH) << "n_websites:"
             <<  std::format("\033[32m{}\033[0m",vm["n_websites"].as<int>()) << endl;
    }
    if(vm.contains("start")) {
        cout << std::left << std::setw(COL_WIDTH) << "start:"
             <<  std::format("\033[32m{}\033[0m",vm["start"].as<std::string>()) << endl;
    }
    if(vm.contains("delay")) {
        cout << std::left << std::setw(COL_WIDTH) << "delay:"
             <<  std::format("\033[32m{}\033[0m",vm["delay"].as<int>()) << endl;
    }
    if(vm.contains("log")) {
        cout << std::left << std::setw(COL_WIDTH) << "log:"
             <<  std::format("\033[32m{}\033[0m",vm["log"].as<std::string>()) << endl;
    }
}

po::variables_map parse_args(int argc, char *argv[]) {
    po::options_description spider_thread_options(USAGE_STATEMENT);
    spider_thread_options.add_options()
    ("help", "HELP print this message")
    ("continue,c", po::value<std::string>(), "CONTINUE_LOG_FILE to resume from [.log | .txt]")
    ("history_log,h", po::value<std::string>()->required(), "HISTORY_FILE to write websites visited [.log |.txt]")
    ("threads,t", po::value<int>()->default_value(1), "THREADS maximum number of threads")
    ("n_websites,n",po::value<int>()->default_value(100), "NUMBER_OF_WEBSITES max number of websites to crawl")
    ("start,s",po::value<std::string>(), "STARTING URL url to start from")
    ("delay,d", po::value<int>()->default_value(300), "DELAY delay in ms for politeness")
    ("log,l", po::value<std::string>()->required(), "LOG_FILE to save PROGRESS");

    po::variables_map vm;
    try {
        // store options
        po::store(po::parse_command_line(argc, argv, spider_thread_options), vm);
        if(vm.contains("help")) { std::cout << spider_thread_options << std::endl; }
        else {
            po::notify(vm);
        }
    }
    catch (std::exception& e) {
        cerr << e.what() << endl;
        cerr << spider_thread_options << endl;
        throw RETURN_EXCEPTION(1);
    }
    if(vm.contains("help")) { throw RETURN_EXCEPTION(0); }
    if(!valid_options(vm)) {
        cerr << spider_thread_options << std::endl;
        throw RETURN_EXCEPTION(1);
    }
    return vm;
}

bool valid_options(const po::variables_map &vm) {
    // check mutually exclusive
    const bool c_flag = vm.contains("continue"),
                   s_flag = vm.contains("start"),
                   n_flag = !vm["number"].defaulted();

    if(c_flag) {
        if(s_flag || n_flag) {
            cerr << "-c flag is mutually exclusive from -s AND -n" << endl;
            return false;
        }
    }
    else {
        if(!s_flag) {
            cerr << "-s flag is required for a new crawl" << endl;
            return false;
        }
    }

    // check history and log if they're valid files
    const std::string history_log = vm["history_log"].as<std::string>(),
                      log = vm["log"].as<std::string>();
    if(!std::regex_match(history_log, FILE_REGEX)) {
        cerr << std::format("{} is not a .txt or .log file", history_log) << std::endl;
        return false;
    }
    if(!std::regex_match(log, FILE_REGEX)) {
        cerr << std::format("{} is not a .txt or .log file", log) << std::endl;
        return false;
    }
    return true;
}
