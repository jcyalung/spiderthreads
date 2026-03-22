#include "include/helpers.h"
#include "include/parseHelpers.h"

int main(int argc, char* argv[]) {

    // TODO: parse args
    po::variables_map vm;
    try {
        vm = parse_args(argc, argv);
    }
    catch (std::exception& e) { return 1; }

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
