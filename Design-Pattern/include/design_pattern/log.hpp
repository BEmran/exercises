//
// Created by bemran on 1/31/23.
//

#ifndef EXERCISES_LOG_HPP
#define EXERCISES_LOG_HPP
#include <iostream>
#include <string>
namespace log {

enum class Level : uint8_t {
  INFO = 1<<0,
  DEBUG = 1<<1,
  WARN = 1<<2,
  ERROR = 1<<3,
};

class ILog {
 public:
  virtual ~ILog() = default;
  virtual void SetLevel ( Level level) = 0;
  virtual void Log( Level level, std::string str) = 0;
};

class StreamLog : public ILog {
 public:
  void SetLevel ( Level level) override;
  void Log( Level level, std::string msg) override;
 private:
  Level level_{Level::INFO};
};
}  // namespace log

#endif  // EXERCISES_LOG_HPP
