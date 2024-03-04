#include <iostream>
#include "person_observer.hpp"
#include "person_subject.hpp"

int main(int, char**) {
    std::cout << "Hello, from oop!\n";
    PersonSubject p1("Bara", "Emran", 123);
    PersonObserver o1;
    PersonObserver o2;
    p1.attach(&o1);
    p1.attach(&o2);
    
    p1.first_name("Khaled");
    p1.detach(&o1);
    p1.last_name("Emrano");
    p1.detach(&o2);
    p1.address(778);
}
