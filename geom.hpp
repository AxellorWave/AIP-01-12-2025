#ifndef GEOM_HPP
#define GEOM_HPP
#include <cstddef>
#include <stdexcept>

namespace top {
  struct p_t {
    int x, y;
  };

  struct frame_t {
    p_t leftBot, rightTop;
  };
  frame_t build_frame(const p_t * ps, size_t s);
  size_t rows(frame_t fr);
  size_t cols(frame_t fr);
  bool operator==(p_t a, p_t b);
  bool operator!=(p_t a, p_t b);
}
#endif
