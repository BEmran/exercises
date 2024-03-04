#pragma once

#include "observer.hpp"

#include <set>
#include <string>

class Person {
public:
  enum class StateChange {
    FIRST_NAME,
    LAST_NAME,
    ADDRESS,
  };
  
  using PersonObserver = Observer<Person, StateChange>;

  Person(std::string fname, std::string lname, uint32_t address);
  
  void notify(StateChange state);

  const std::string &first_name() const;
  const std::string &last_name() const;
  uint32_t address() const;

  void first_name(std::string fname);
  void last_name(std::string lname);
  void address(uint32_t address);

  bool attach(PersonObserver *obs);
  bool detach(PersonObserver *obs);

private:
  std::string m_first_name;
  std::string m_last_name;
  uint32_t m_address;
  std::set<PersonObserver*> m_obs;
};
