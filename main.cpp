#include "include/helpers.h"
#include "include/parseHelpers.h"
#include <csignal>
volatile std::sig_atomic_t sigint_flag;

void sigint_handler(int) { sigint_flag = 1; }

int main(int argc, char* argv[]) {

    // TODO: parse args
    po::variables_map vm;
    try {
        vm = parse_args(argc, argv);
    }
    catch (RETURN_EXCEPTION& e) { return e.code; }

    auto start = boost::urls::parse_uri(vm["start"].as<std::string>());
    if(start) {
        const auto& start_url = *start;
        cout << start_url << endl;
    }
    else {
        cerr << std::format("{} is not a starting url", vm["start"].as<std::string>()) << endl;
        return 1;
    }

    // print out args
    print_args(vm);
    return 0;
}
