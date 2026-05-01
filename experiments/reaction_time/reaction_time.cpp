#include <iostream>
#include <chrono>
#include <thread>
#include <random>

namespace chrono = std::chrono;
using Clock = std::chrono::steady_clock;
// std::seconds but double
using Seconds = std::chrono::duration<double>;

std::random_device rd{};
std::seed_seq seed_seq{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
std::mt19937 eng{seed_seq};

int main() {
    auto rand_time{std::uniform_real_distribution{1.0, 15.0}(eng)};
    auto wait{Clock::now() + static_cast<Seconds>(rand_time)};

    while (Clock::now() <= wait) {
        std::cout << "\rWait.  " << std::flush;
        std::this_thread::sleep_for(chrono::milliseconds(300));

        std::cout << "\rWait.. " << std::flush;
        std::this_thread::sleep_for(chrono::milliseconds(300));

        std::cout << "\rWait..." << std::flush;
        std::this_thread::sleep_for(chrono::milliseconds(300));
    }

    std::cout << "\rGo! (Press [ENTER]).\n";
    auto t0{Clock::now()};
    std::cin.get();
    auto t1{Clock::now()};
    auto reaction{t1 - t0};

    std::cout << "Reaction time:\n";
    std::cout << '\t' << Seconds(reaction) << '\n';
}