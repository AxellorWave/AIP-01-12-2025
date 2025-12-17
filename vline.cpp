#include "vline.hpp"

top::Vline::Vline(int x, int y, int l):
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

top::Vline::Vline(p_t p, int l):
  Vline(p.x, p.y, l)
{}

top::p_t top::Vline::begin() const
{
  return start;
}

top::p_t top::Vline::next(p_t p) const
{
  if (p.y == start.y + len - 1) {
    return start;
  }
  return {p.x, p.y + 1};
}
