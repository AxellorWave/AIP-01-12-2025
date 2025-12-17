#ifndef RECTANGLEFILLED_HPP
#define RECTANGLEFILLED_HPP
#include "idraw.hpp"

namespace top {
  struct RectangleFilled: IDraw {
    RectangleFilled(int x, int y, int a, int b);
    RectangleFilled(p_t p, int a, int b);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int a_, b_;
  };
}
#endif
