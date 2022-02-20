
#ifndef AIS1002_LAB_WEEK_6_EXERCISE1_HPP
#define AIS1002_LAB_WEEK_6_EXERCISE1_HPP

#include <algorithm>
#include <cctype>
#include <numeric>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace ais1002 {

    double multiplyDoubles(double a, double b) {
        return a * b;
    }

    int computeSum(const std::vector<int> &values) {
        // could use a simple for loop too..
        return std::accumulate(values.begin(), values.end(), 0);
    }

    int countValuesBelowThreshold(const std::vector<double> &values) {
        // could use a simple for loop too..
        return (int) std::count_if(values.begin(), values.end(),
                                   [](double d) { return d < 50; });
    }

    void capitalizeString(std::string &str) {
        if (str.empty()) return; // early return if str is empty
        str[0] = static_cast<char>(std::toupper(str[0]));
        // could make sure that the remaining characters are lowercase too
    }

    std::unordered_map<std::string, int>
    convert(const std::vector<std::pair<std::string, int>> &list) {
        std::unordered_map<std::string, int> m;
        for (auto &pair: list) {
            m[pair.first] = pair.second;
            // m.insert(pair);
        }
        return m;
    }

} // namespace ais1002

#endif // AIS1002_LAB_WEEK_6_EXERCISE1_HPP
