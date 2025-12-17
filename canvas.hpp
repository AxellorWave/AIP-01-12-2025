#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <iosfwd>
#include "geom.hpp"

namespace top {
  char * build_canvas(frame_t f, char fill);
  void paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f);
  void print_canvas(std::ostream & os, const char * cnv, frame_t fr);
}
#endif
