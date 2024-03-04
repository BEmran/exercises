#pragma once

class Circle {
public:
  explicit Circle(int center, int radius);
  int get_radius() const;
  void set_radius(int r);
  void move(int c);
  void draw() const;

private:
  int m_center;
  int m_radius;
};
