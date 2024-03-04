#pragma once
#include "shape.hpp"

class Square : public Shape {
public:
  explicit Square(int width);
  int get_width() const;
  void set_width(int w);
  void draw() override;
  
private:
  int m_width;
};
