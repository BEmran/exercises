#include "square.hpp"
#include "iostream"

Square::Square(int width) : Shape(ShapeType::SQUARE), m_width{width} {}

int Square::get_width() const { return m_width; }

void Square::set_width(int w) { m_width = w; }

void Square::draw() {
    std::cout << "Draw this square\n";
}