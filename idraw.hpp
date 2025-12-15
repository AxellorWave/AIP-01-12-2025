#ifndef IDRAW_HPP
#define IDRAW_HPP
#include "geom.hpp"
#include <cstddef>

namespace top {
  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
    virtual ~IDraw() = default;
  };
  size_t get_points(IDraw * b, p_t ** ps, size_t & s);
}
#endif