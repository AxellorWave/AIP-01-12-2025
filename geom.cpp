#include "geom.hpp"

bool top::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}
bool top::operator!=(p_t a, p_t b)
{
  return !(a == b);
}

size_t top::rows(frame_t fr) 
{
  return (fr.rightTop.y - fr.leftBot.y + 1);
}

size_t top::cols(frame_t fr) 
{
  return (fr.rightTop.x - fr.leftBot.x + 1);
}