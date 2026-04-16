#include <chrono>
#include <iostream>
#include <thread>

using Clock = std::chrono::steady_clock;
using Duration = std::chrono::seconds;
using TimePoint = std::chrono::time_point<Clock>;

// a random function
void f() { std::cout << "hello world!\n"; }

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: scheduler <DURATION> <INTERVAL>\n";
        std::exit(EXIT_FAILURE);
    }

    Duration duration{std::stoi(argv[1])};
    Duration interval{std::stoi(argv[2])};

    auto start{Clock::now()};
    auto end{start + duration};

    while (Clock::now() <= end) {
        std::this_thread::sleep_until(Clock::now() + interval);
        f();
    }
}