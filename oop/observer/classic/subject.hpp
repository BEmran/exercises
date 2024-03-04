#pragma once

#include <set>
#include "observer.hpp"

class Observer;

class Subject {
public:
  virtual ~Subject() = default;

  bool attach(Observer *obs);
  bool detach(Observer *obs);
  void notify();

private:
  std::set<Observer*> m_obs;
};
