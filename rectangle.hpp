#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "idraw.hpp"

namespace top {
  struct Rectangle: IDraw {
    Rectangle(int x, int y, int a, int b);
    Rectangle(p_t p, int a, int b);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int a_, b_;
  };
}
#endif
