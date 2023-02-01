//
// Created by bemran on 1/31/23.
//

#include "design_pattern/log.hpp"

namespace log {

namespace {
std::string LevelString(Level level) {
  switch (level) {
    case Level::INFO:
      return "INFO";
    case Level::DEBUG:
      return "DEBUG";
    case Level::WARN:
      return "WARN";
    case Level::ERROR:
      return "ERROR";
    default:
      std::cerr << "UNDEFINED Level" << std::endl;
      return "";
  }
}

std::ostream& operator<< (std::ostream& os, Level level) {
  return os << LevelString(level);
}

uint8_t LevelToUnit8(Level level) {
  return static_cast<uint8_t>(level);
}

bool operator>=(Level lhs, Level rhs) {
  return LevelToUnit8(lhs) >= LevelToUnit8(rhs);
}
}  // namespace

void StreamLog::SetLevel(Level level) {
  level_ = level;
}

void StreamLog::Log(Level level, std::string msg) {
  if (level >= level_) {
    std::cout << "[" << level << "]: " << msg << std::endl;
  }
}
}  // namespace log