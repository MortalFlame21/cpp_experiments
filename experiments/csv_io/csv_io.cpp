#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <tuple>

using CsvEntry = std::tuple<std::string, int, double>;

std::ostream& operator<<(std::ostream& os, const CsvEntry& e) {
    return os << std::get<0>(e) << ',' << std::get<1>(e) << ',' << std::get<2>(e);
}

// take in std::string, int, double.
std::istream& operator>>(std::istream& is, CsvEntry& e) {
    char c{};
    while (is.get(c) && c != ',')
        std::get<0>(e) += c;

    if (!(is >> std::get<1>(e)))
        is.setstate(std::ios_base::failbit);

    if (!(is >> c >> std::get<2>(e)) || c != ',')
        is.setstate(std::ios_base::failbit);

    return is;
}

int main() {
    std::vector<CsvEntry> entries{};
    std::cout << "Enter CSV entries (std::string, int, double)\n"
                "\t(CTRL+d to complete):\n";
    for (CsvEntry e{}; std::cin >> e;)
        entries.push_back(e);
    if (std::cin.eof() && std::cin) std::cin.clear();

    if (!std::cin) {
        std::cerr << "ERROR: An error occurred when taking io.\n";
        std::exit(EXIT_FAILURE);
    }

    for (const auto& e : entries)
        std::cout << e << '\n';
}