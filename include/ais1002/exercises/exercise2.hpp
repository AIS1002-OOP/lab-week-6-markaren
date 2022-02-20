
#ifndef AIS1002_LAB_WEEK_6_EXERCISE2_HPP
#define AIS1002_LAB_WEEK_6_EXERCISE2_HPP

#include "../real_random_generator.hpp"

namespace ais1002 {

    std::vector<double> generateRandomNumbersInRange(int count, double min, double max) {
        real_random_generator rng(min, max);
        std::vector<double> v(count); //we know the size
        for (auto &d: v) {
            d = rng();
        }
        return v;
    }

} // namespace ais1002

#endif // AIS1002_LAB_WEEK_6_EXERCISE2_HPP
