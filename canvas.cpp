#include "canvas.hpp"
#include <iostream>

char * top::build_canvas(frame_t f, char fill)
{
  char * cnv =  new char[rows(f) * cols(f)];
  for (size_t i = 0; i < rows(f) * cols(f); ++i) {
    cnv[i] = fill; 
  }
  return cnv;
}

void top::paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f)
{
  for (size_t i = 0; i < k; ++i) {
    int dx = ps[i].x - fr.leftBot.x;
    int dy = fr.rightTop.y - ps[i].y;
    cnv[dy * cols(fr) + dx] = f;
  }
  
}

void top::print_canvas(std::ostream & os, const char * cnv, frame_t fr)
{
  for (size_t i = 0; i < rows(fr); ++i) {
    for (size_t j = 0; j < cols(fr); ++j) {
      os << cnv[i * cols(fr) + j];
    }
    os << "\n";
  }
}