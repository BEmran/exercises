#include "person_observer.hpp"
#include <iostream>

void PersonObserver::update(const Subject& sub) {
    const auto& ps = static_cast<const PersonSubject&>(sub);
    std::cout << "update happen ->" //
              << " first name: " << ps.first_name() //
              << " last name: " << ps.last_name() //
              << " address: " << ps.address() //
              << std::endl;
}
