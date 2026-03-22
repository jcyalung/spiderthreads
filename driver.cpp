#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>

// Use a volatile atomic flag for signal safety
volatile std::sig_atomic_t program_interrupted = false;

extern "C" void signal_handler(int signum) {
    program_interrupted = true;
    // Reinstall handler for certain systems if needed, though modern C++ handles this differently
    // std::signal(signum, signal_handler); 
}

int main() {
    // Register the signal handler for SIGINT
    std::signal(SIGTERM, signal_handler);

    std::cout << "Program running. Press Ctrl+C to exit gracefully." << std::endl;

    while (!program_interrupted) {
        // Main program logic
        std::cout << "Going to sleep...." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Check the flag periodically
        if (program_interrupted) {
            break;
        }
    }

    std::cout << "Interrupt signal (" << SIGTERM << ") received. Exiting." << std::endl;
    
    // Perform cleanup operations here
    // ...

    return 0;
}
