#include <chrono>
#include <iostream>

namespace cno = std::chrono;
using Clock = std::chrono::system_clock;

int main() {
    cno::zoned_time zone_curr(cno::current_zone(), Clock::now());
    cno::zoned_time zone_au(cno::locate_zone("Australia/Melbourne"), Clock::now());
    cno::zoned_time zone_ph(cno::locate_zone("Asia/Manila"), Clock::now());
    cno::zoned_time zone_ny(cno::locate_zone("America/Detroit"), Clock::now());
    cno::zoned_time zone_jp(cno::locate_zone("Japan"), Clock::now());

    std::cout << zone_curr.get_local_time() << '\n';
    std::cout << zone_ny.get_local_time() << '\n';
    std::cout << zone_au.get_local_time() << '\n';
    std::cout << zone_ph.get_local_time() << '\n';
    std::cout << zone_jp.get_local_time() << '\n';
}
