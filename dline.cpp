#include "dline.hpp"

top::Dline::Dline(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len == 0) {
    throw std::invalid_argument("lenght can not be 0");
  }
  if (len < 0) {
    len *= -1;
    start.y -= len;
  }
}

top::Dline::Dline(p_t p, int l):
  Dline(p.x, p.y, l)
{}

top::p_t top::Dline::begin() const
{
  return start;
}

top::p_t top::Dline::next(p_t p) const
{
  if (p.y == start.y + len - 1) {
    return start;
  }
  return {p.x + 1, p.y + 1};
}
