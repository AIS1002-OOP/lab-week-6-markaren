
#ifndef AIS1002_LAB_WEEK_6_REAL_RANDOM_GENERATOR_HPP
#define AIS1002_LAB_WEEK_6_REAL_RANDOM_GENERATOR_HPP

#include <random>

namespace ais1002 {

// Class used to produced high quality random numbers
    class real_random_generator {

    public:
        real_random_generator() : real_random_generator(0.0, 1.0) {}

        real_random_generator(double min, double max) : dev(), gen(dev()), dis(min, max) {}

        // Generates and returns new random number when invoked
        double operator()() { return dis(gen); }

    private:
        std::random_device dev;
        std::mt19937 gen;
        std::uniform_real_distribution<> dis;
    };

} // namespace ais1002

#endif // AIS1002_LAB_WEEK_6_REAL_RANDOM_GENERATOR_HPP
