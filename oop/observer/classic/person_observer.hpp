#pragma once

#include "person_subject.hpp"
#include "observer.hpp"

class PersonObserver : public Observer {
public:
    void update(const Subject& sub) override;
};