#ifndef DLINE_HPP
#define DLINE_HPP
#include "idraw.hpp"

namespace top {
  struct Dline: IDraw {
    Dline(int x, int y, int l);
    Dline(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

}
#endif
