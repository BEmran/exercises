#pragma once

#include "observer.hpp"
#include "person.hpp"

class AddressObserver : public Observer<Person, Person::StateChange> {
public:
    void update(const Person& person, Person::StateChange tag) override;
};