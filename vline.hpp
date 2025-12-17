#ifndef VLINE_HPP
#define VLINE_HPP
#include "idraw.hpp"

namespace top {
  struct Vline: IDraw {
    Vline(int x, int y, int l);
    Vline(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };
}
#endif
