#include <iostream>
#include <thread>

void print_message(const std::string& msg, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << msg << "\n";
    }
}

int main() {
    // 1. Launch thread with a function and its arguments
    std::thread t(print_message, "Hello from worker thread", 3);



   

    // 3. Wait for the thread to finish before exiting
    if (t.joinable()) {
        t.join();
    }

    return 0;
}

