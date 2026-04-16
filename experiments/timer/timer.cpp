#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

namespace cno = std::chrono;

using SteadyClock = std::chrono::steady_clock;
using TimePoint = cno::time_point<SteadyClock>;
using BigNum = unsigned long long;

class Timer {
public:
    Timer() { }
    ~Timer() { }

    void reset() {
        time = SteadyClock::now();
    }

    template<typename t>
    double elapsed() {
        return cno::duration_cast<t>(SteadyClock::now() - time).count();
    }
private:
    cno::time_point<SteadyClock> time{SteadyClock::now()};
};

constexpr BigNum factorial_n(BigNum n) {
    if (n < 1) return 1;
    return n * factorial_n(n - 1);
}

int main () {
    std::vector<int> nums{};
    for (int i{}; i <= 20; ++i)
        nums.push_back(i);

    for (const auto& n : nums) {
        Timer time{};
        auto f{factorial_n(n)};
        auto e{time.elapsed<cno::nanoseconds>()};
        std::cout << "took " << e << " nanoseconds for factorial(" << n << ") = " << f << "\n";
    }
}