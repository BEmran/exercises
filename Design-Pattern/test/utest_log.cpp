// Copyright (C) 2022 Bara Emran - All Rights Reserved

#include <gtest/gtest.h>

#include "design_pattern/log.hpp"

using Level = log::Level;
using log::StreamLog;

TEST(Level, InfoValue) {
  EXPECT_EQ(1, static_cast<uint8_t>(Level::INFO));
}

TEST(Level, DebugValue) {
  EXPECT_EQ(2, static_cast<uint8_t>(Level::DEBUG));
}

TEST(Level, WarnValue) {
  EXPECT_EQ(4, static_cast<uint8_t>(Level::WARN));
}

TEST(Level, ErrorValue) {
  EXPECT_EQ(8, static_cast<uint8_t>(Level::ERROR));
}

/******************************************************************************/

class StreamLogFixture : public StreamLog {
 public:
  Level GetLevel() {
    return level_;
  }
};

TEST(StreamLogFixture, SetLevelToInfo) {
  StreamLogFixture slf;
  Level expect = Level::INFO;
  slf.SetLevel(expect);
  EXPECT_EQ(expect, slf.GetLevel());
}

TEST(StreamLogFixture, SetLevelToDebug) {
  StreamLogFixture slf;
  Level expect = Level::DEBUG;
  slf.SetLevel(expect);
  EXPECT_EQ(expect, slf.GetLevel());
}

TEST(StreamLogFixture, SetLevelToWarn) {
  StreamLogFixture slf;
  Level expect = Level::WARN;
  slf.SetLevel(expect);
  EXPECT_EQ(expect, slf.GetLevel());
}

TEST(StreamLogFixture, SetLevelToError) {
  StreamLogFixture slf;
  Level expect = Level::ERROR;
  slf.SetLevel(expect);
  EXPECT_EQ(expect, slf.GetLevel());
}