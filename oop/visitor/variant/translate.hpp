#include <iostream>

#include "circle.hpp"
#include "shape.hpp"
#include "square.hpp"

void translate_all(Shapes &shapes, int dis) {
  for (auto &shape : shapes) {
    if (Circle *c = std::get_if<Circle>(&shape)) {
      c->move(dis);
    } else if (Square *s = std::get_if<Square>(&shape)) {
      s->move(dis);
    } else {
      throw std::runtime_error("undefined type!");
    }
  }
}
