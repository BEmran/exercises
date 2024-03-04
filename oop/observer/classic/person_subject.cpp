#include "person_subject.hpp"

PersonSubject::PersonSubject(std::string fname, std::string lname,
                             uint32_t address)
    : m_first_name{std::move(fname)}, m_last_name{std::move(lname)}, m_address{address} {}

const std::string &PersonSubject::first_name() const { return m_first_name; }

const std::string &PersonSubject::last_name() const { return m_last_name; }

uint32_t PersonSubject::address() const { return m_address; }

void PersonSubject::first_name(std::string fname) {
  m_first_name = fname;
  notify();
}

void PersonSubject::last_name(std::string lname) {
  m_last_name = lname;
  notify();
}

void PersonSubject::address(uint32_t address) {
  m_address = address;
  notify();
}
