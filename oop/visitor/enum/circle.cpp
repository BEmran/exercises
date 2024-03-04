#include "circle.hpp"
#include "iostream"

Circle::Circle(int radius) : Shape(ShapeType::CIRCLE), m_radius{radius} {}

int Circle::get_radius() const { return m_radius; }

void Circle::set_radius(int r) { m_radius = r; }

void Circle::draw() {
    std::cout << "Draw this circle\n";
}