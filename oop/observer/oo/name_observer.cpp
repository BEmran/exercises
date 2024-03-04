#include "name_observer.hpp"
#include <iostream>

void NameObserver::update(const Person &person, Person::StateChange tag) {
  if (Person::StateChange::FIRST_NAME == tag) {
    std::cout << "First name: " << person.first_name() << std::endl;
  } else if (Person::StateChange::LAST_NAME == tag) {
    std::cout << "Last name: " << person.last_name() << std::endl;
  } else {
    std::cout << "not subs\n";
  }
}