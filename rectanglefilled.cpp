#include "rectangle.hpp"

top::RectangleFilled::RectangleFilled(int x, int y, int a, int b):
  IDraw(),
  start{x, y},
  a_(a),
  b_(b)
{
  if (a_ <= 0 || b_ <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::RectangleFilled::RectangleFilled(p_t p, int a, int b):
  RectangleFilled(p.x, p.y, a, b)
{}

top::p_t top::RectangleFilled::begin() const
{
  return start;
}

top::p_t top::RectangleFilled::next(p_t p) const
{
  if (p.x < start.x + b_ - 1) {
    return {p.x + 1, p.y};
  } else if (p.y < start.y + a_ - 1) {
    return {start.x, p.y + 1};
  }
  return start;
}
