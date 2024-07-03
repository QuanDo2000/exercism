#include <string>

namespace log_line {
std::string message(std::string line) {
    std::string delimiter = ": ";
    std::string res = line.substr(line.find(delimiter) + delimiter.length());
    return res;
}

std::string log_level(std::string line) {
    std::string end = "]";
    std::string res = line.substr(1, line.find(end) - end.length());
    return res;
}

std::string reformat(std::string line) {
    std::string message = log_line::message(line);
    std::string log = log_line::log_level(line);

    return message + " (" + log + ")";
}
}  // namespace log_line
