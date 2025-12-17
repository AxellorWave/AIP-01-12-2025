#include "hline.hpp"

top::Hline::Hline(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len == 0) {
    throw std::invalid_argument("lenght can not be 0");
  }
  if (len < 0) {
    len *= -1;
    start.x -= len;
  }
}

top::Hline::Hline(p_t p, int l):
  Hline(p.x, p.y, l)
{}

top::p_t top::Hline::begin() const
{
  return start;
}

top::p_t top::Hline::next(p_t p) const
{
  if (p.x == start.x + len - 1) {
    return start;
  }
  return {p.x + 1, p.y};
}
