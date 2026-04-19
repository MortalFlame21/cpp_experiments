#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <ranges>

namespace chrono = std::chrono;
using Clock = std::chrono::system_clock;

void print_zone(const chrono::time_zone* tz, const Clock::time_point& tp) {
    std::cout << tz->name() << " - " << tz->to_local(tp) << '\n';
}

std::vector<const chrono::time_zone*> get_tz_vec(const chrono::tzdb& tzdb) {
    constexpr auto time_zones{std::to_array({"Australia/Melbourne", "Asia/Manila",
                                             "Japan", "America/New_York"})};

    std::vector<const chrono::time_zone*> tz_vec(time_zones.size());
    std::ranges::transform(time_zones, tz_vec.begin(),
        [&](const auto& tz) { return tzdb.locate_zone(tz); });

    return tz_vec;
}

int main() {
    const auto tz_vec{get_tz_vec(chrono::get_tzdb())};

    while (true) {
        const auto now{Clock::now()};

        for (const auto& tz : tz_vec)
            print_zone(tz, now);
        std::cout << "\x1B[" << tz_vec.size() << "A" << std::flush;

        std::this_thread::sleep_for(chrono::seconds(1));
    }
}
