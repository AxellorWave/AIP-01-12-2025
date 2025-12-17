#include "square.hpp"

top::Square::Square(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::Square::Square(p_t p, int l):
  Square(p.x, p.y, l)
{}

top::p_t top::Square::begin() const
{
  return start;
}

top::p_t top::Square::next(p_t p) const
{
  if (p.x == start.x && p.y < start.y + len - 1) {
    return {p.x, p.y + 1};
  }
  if (p.y == start.y + len - 1 && p.x < start.x + len - 1) {
    return {p.x + 1, p.y};
  }
  if (p.x == start.x + len - 1 && p.y > start.y) {
    return {p.x, p.y - 1};
  }
  if (p.y == start.y && p.x > start.x) {
    return {p.x - 1, p.y};
  }
  return start;
}
