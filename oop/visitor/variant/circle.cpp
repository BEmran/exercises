#include <iostream>

#include "circle.hpp"

Circle::Circle(int center, int radius) : m_center{center}, m_radius{radius} {}

int Circle::get_radius() const { return m_radius; }

void Circle::set_radius(int r) { m_radius = r; }

void Circle::move(int c) { m_center += c; }

void Circle::draw() const { std::cout << "Draw this circle\n"; }