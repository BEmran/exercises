#pragma once

#include "observer.hpp"
#include <string>

class PersonSubject : public Subject {
public:
  PersonSubject(std::string fname, std::string lname, uint32_t address);

  const std::string &first_name() const;
  const std::string &last_name() const;
  uint32_t address() const;

  void first_name(std::string fname);
  void last_name(std::string lname);
  void address(uint32_t address);

private:
  std::string m_first_name;
  std::string m_last_name;
  uint32_t m_address;
};
