
#ifndef AIS1002_LAB_WEEK_6_EXERCISE3_HPP
#define AIS1002_LAB_WEEK_6_EXERCISE3_HPP

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace ais1002 {

    std::string readTextFile(const std::filesystem::path &path) {
        std::ifstream f(path);

        std::stringstream ss; // stringstream is more effective that std::string for appending
        for (std::string s; std::getline(f, s);) {
            ss << s << "\n";
        }

        return ss.str();
    }

    void writeTextToFile(const std::filesystem::path &path, const std::string &data) {
        std::ofstream o(path);
        o << data;
    }

} // namespace ais1002

#endif // AIS1002_LAB_WEEK_6_EXERCISE3_HPP
