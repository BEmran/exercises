#pragma once
#include "shape.hpp"

class Circle : public Shape {
public:
  explicit Circle(int radius);
  int get_radius() const;
  void set_radius(int r);
  void draw() override;

private:
  int m_radius;
};
