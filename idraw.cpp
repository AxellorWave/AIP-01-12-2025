#include "idraw.hpp"
using p_t = top::p_t;

void extend(p_t ** pts, size_t s, p_t p)
{
  p_t * res = new p_t[s + 1];
  for (size_t i = 0; i < s; ++i) {
    res[i] = (*pts)[i];
  }
  res[s] = p;
  delete[] *pts;
  *pts = res;
}

size_t top::get_points(IDraw * b, p_t ** ps, size_t & s)
{
  p_t p = b->begin();
  extend(ps, s, p);
  size_t delta = 1;
  while (b->next(p) != b->begin()) {
    p = b->next(p);
    extend(ps, s + delta, p);
    ++delta;
  }
  return s+=delta;
}