#ifndef SQUAREFILLED_HPP
#define SQUAREFILLED_HPP
#include "idraw.hpp"

namespace top {
  struct SquareFilled: IDraw {
    SquareFilled(int x, int y, int l);
    SquareFilled(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };
}
#endif
