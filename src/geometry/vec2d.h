#ifndef VEC2D_H
#define VEC2D_H

class Vec2d {
 public:
  float x, y;

  Vec2d();
  Vec2d(float x_, float y_);

  Vec2d operator+(const Vec2d& other);
  Vec2d& operator+=(const Vec2d& other);
  Vec2d operator*(const float& other);
  Vec2d& operator*=(const Vec2d& other);
};

#endif  // !VEC2D_H