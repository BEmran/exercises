#pragma once

enum class ShapeType {
  CIRCLE,
  RECTANGLE,
  SQUARE,
};

class Shape {
public:
  explicit Shape(ShapeType type);
  virtual ~Shape() = default;
  ShapeType get_type() const;
  virtual void draw() = 0;

private:
  ShapeType m_type;
};