#include <iostream>
#include "person.hpp"
#include "name_observer.hpp"
#include "address_observer.hpp"

int main(int, char**) {
    std::cout << "Hello, from oop!\n";
    Person p1("Bara", "Emran", 123);
    NameObserver o1;
    AddressObserver o2;
    p1.attach(&o1);
    p1.attach(&o2);
    
    p1.first_name("Khaled");
    p1.last_name("Emrano");
    p1.address(778);
}
