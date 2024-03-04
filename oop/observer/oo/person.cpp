#include "person.hpp"

Person::Person(std::string fname, std::string lname,
                             uint32_t address)
    : m_first_name{std::move(fname)}, m_last_name{std::move(lname)}, m_address{address} {}

const std::string &Person::first_name() const { return m_first_name; }

const std::string &Person::last_name() const { return m_last_name; }

uint32_t Person::address() const { return m_address; }

void Person::first_name(std::string fname) {
  m_first_name = fname;
  notify(StateChange::FIRST_NAME);
}

void Person::last_name(std::string lname) {
  m_last_name = lname;
  notify(StateChange::LAST_NAME);
}

void Person::address(uint32_t address) {
  m_address = address;
  notify(StateChange::ADDRESS);
}

bool Person::attach(PersonObserver *obs) {
    auto [pos, success] = m_obs.insert(obs);
    return success;
}

bool Person::detach(PersonObserver *obs) {
    return m_obs.erase(obs) > 0U;
}

void Person::notify(StateChange state) {
    for(auto& obs : m_obs) {
        obs->update(*this, state);
    }
}