#include <iostream>
#include "person.hpp"
#include "observer.hpp"

void address_change(const Person& person, Person::StateChange state) {
  if (Person  ::StateChange::ADDRESS == state) {
    std::cout << "Address: " << person.address() << std::endl;
  } else {
    std::cout << "not subs\n";
  }
}

int main(int, char**) {
    std::cout << "Hello, from oop!\n";

    auto name_change = [](const Person& person, Person::StateChange state) {
        if (Person::StateChange::FIRST_NAME == state) {
            std::cout << "First name: " << person.first_name() << std::endl;
        } else if (Person::StateChange::LAST_NAME == state) {
            std::cout << "Last name: " << person.last_name() << std::endl;
        } else {
            std::cout << "not subs\n";
        }
    };

    Person p1("Bara", "Emran", 123);
    Person::PersonObserver o1(address_change);
    Person::PersonObserver o2(name_change);
    p1.attach(&o1);
    p1.attach(&o2);
    
    p1.first_name("Khaled");
    p1.last_name("Emrano");
    p1.address(778);
}
