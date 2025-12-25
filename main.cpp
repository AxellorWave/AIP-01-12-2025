#include <iostream>
#include "tdraw.hpp"

namespace top {
  void make_f(IDraw ** b);
}

int main()
{
  size_t size = 8;
  int err = 0;
  top::IDraw * f[size] = {};
  top::p_t * p = nullptr;
  char * cnv = nullptr;
  size_t s = 0; 
  try {
    make_f(f);
    for (size_t i = 0; i < size; ++i) {
      get_points(f[i], &p, s);
    }
    top::frame_t fr = top::build_frame(p, s);
    cnv = top::build_canvas(fr, ' ');
    top::paint_canvas(cnv, fr, p, s, '$');
    top::print_canvas(std::cout, cnv, fr);
  } catch (...) {
    err = 1;
  }
  for (size_t i = 0; i < size; ++i) {
    delete f[i];
  }
  delete[] p;
  delete[] cnv;
  return err;
}

void top::make_f(IDraw ** b)
{
  b[0] = new Dot(0, 0);
  b[1] = new Hline({-1, -5}, 5);
  b[2] = new SquareFilled(15, 7, 5);
  b[3] = new Dline(0, 3, 4);
  b[4] = new Vline(11, 8, 7);
  b[5] = new RectangleFilled(20, 16, 3, 7);
  b[6] = new Square(25, 30, 7);
  b[7] = new Rectangle(80,0, 15, 17);
}
