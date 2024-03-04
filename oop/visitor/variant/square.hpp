#pragma once

class Square {
public:
  explicit Square(int center, int width);
  int get_width() const;
  void set_width(int w);
  void move(int c);
  void draw() const;
  
private:
  int m_center;
  int m_width;
};
