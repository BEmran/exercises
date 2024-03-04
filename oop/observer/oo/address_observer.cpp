#include "address_observer.hpp"
#include <iostream>

void AddressObserver::update(const Person &person, Person::StateChange tag) {
  if (Person::StateChange::ADDRESS == tag) {
    std::cout << "Address: " << person.address() << std::endl;
  } else {
    std::cout << "not subs\n";
  }
}