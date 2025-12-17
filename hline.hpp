#ifndef HLINE_HPP
#define HLINE_HPP
#include "idraw.hpp"

namespace top {
  struct Hline: IDraw {
    Hline(int x, int y, int l);
    Hline(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };
}
#endif
