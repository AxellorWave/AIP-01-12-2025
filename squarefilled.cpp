#include "squarefilled.hpp"

top::SquareFilled::SquareFilled(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::SquareFilled::SquareFilled(p_t p, int l):
  SquareFilled(p.x, p.y, l)
{}

top::p_t top::SquareFilled::begin() const
{
  return start;
}

top::p_t top::SquareFilled::next(p_t p) const
{
  if (p.x < start.x + len - 1) {
    return {p.x + 1, p.y};
  } else if (p.y < start.y + len - 1) {
    return {start.x, p.y + 1};
  }
  return start;
}
