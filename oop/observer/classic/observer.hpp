#pragma once

#include "subject.hpp"

class Subject;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const Subject& sub) = 0;
};