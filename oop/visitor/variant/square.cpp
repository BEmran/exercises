#include <iostream>

#include "square.hpp"

Square::Square(int center, int width) : m_center{center}, m_width{width} {}

int Square::get_width() const { return m_width; }

void Square::set_width(int w) { m_width = w; }

void Square::move(int c) { m_center += c; }

void Square::draw() const { std::cout << "Draw this square\n"; }