//
// Created by bemran on 1/31/23.
//
#include <cstdlib>
#include <iostream>
#include "design_pattern/log.hpp"
int main(int /*argc*/, char** /*argv*/) {
  log::StreamLog logger;
  logger.Log(log::Level::INFO, "run successfully");
  return EXIT_SUCCESS;
}