#include "rectangle.hpp"

top::Rectangle::Rectangle(int x, int y, int a, int b):
  IDraw(),
  start{x, y},
  a_(a),
  b_(b)
{
  if (a_ <= 0 || b_ <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::Rectangle::Rectangle(p_t p, int a, int b):
  Rectangle(p.x, p.y, a, b)
{}

top::p_t top::Rectangle::begin() const
{
  return start;
}

top::p_t top::Rectangle::next(p_t p) const
{
  if (p.x == start.x && p.y < start.y + a_ - 1) {
    return {p.x, p.y + 1};
  }
  if (p.y == start.y + a_ - 1 && p.x < start.x + b_ - 1) {
    return {p.x + 1, p.y};
  }
  if (p.x == start.x + b_ - 1 && p.y > start.y) {
    return {p.x, p.y - 1};
  }
  if (p.y == start.y && p.x > start.x) {
    return {p.x - 1, p.y};
  }
  return start;
}
