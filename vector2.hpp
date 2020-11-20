#pragma once
#include "concepts.hpp"

template<typename T>
struct Vector2 {
  T x;
  T y;

  Vector2() = default;
  Vector2(const T &x, const T &y): x(x), y(y){};
  Vector2(T &&x, T &&y): x(std::move(x)), y(std::move(y)){};

  template<typename Tother>
  Vector2 operator+(const Vector2<Tother> &v) const requires(Addable<T, Tother>) {
    return Vector2(x + v.x, y + v.y);
  };
  template<typename Tother>
  Vector2 operator-(const Vector2<Tother> &v) const requires(Subtractable<T, Tother>) {
    return Vector2(x - v.x, y - v.y);
  };
  template<typename Tother>
  Vector2 operator*(const Vector2<Tother> &v) const requires(Multipliable<T, Tother>) {
    return Vector2(x * v.x, y * v.y);
  };
  template<typename Tother>
  Vector2 operator/(const Vector2<Tother> &v) const requires(Devidable<T, Tother>) {
    return Vector2(x / v.x, y / v.y);
  };

  template<typename Tother>
  Vector2 operator+(const Tother &v) const requires(Addable<T, Tother>) {
    return Vector2(x + v, y + v);
  };
  template<typename Tother>
  Vector2 operator-(const Tother &v) const requires(Subtractable<T, Tother>) {
    return Vector2(x - v, y - v);
  };
  template<typename Tother>
  Vector2 operator*(const Tother &v) const requires(Multipliable<T, Tother>) {
    return Vector2(x * v, y * v);
  };
  template<typename Tother>
  Vector2 operator/(const Tother &v) const requires(Devidable<T, Tother>) {
    return Vector2(x / v, y / v);
  };
};
