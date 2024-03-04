#include "shape.hpp"

Shape::Shape(ShapeType type): m_type{type} {}

ShapeType Shape::get_type() const {return m_type;}