#include <iostream>

namespace top {
  struct p_t {
    int x, y;
  };

  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next() const = 0;
  };

  struct Dot: IDraw {
    p_t o;
    Dot(int x, int y);
    p_t begin() const override;
    p_t next() const override;
  };

  struct Frame_t {
    p_t leftBot, rightTop;
  };

  void makeF(IDraw ** b, size_t k) {}
  void getPoints(IDraw * b, p_t ** ps, size_t & s) {}
  Frame_t build_frame(const p_t * ps, size_t s) {}
  char * build_canvas(Frame_t f) {}
  void paintCanvas(char * cnv, Frame_t fr, const p_t * ps, size_t k, char f) {}
  void printCanvas(const char * cnv, Frame_t fr) {}
  bool operator==(p_t a, p_t b)
  {
    return a.x == b.x && a.y == b.y;
  }
  
  bool operator!=(p_t a, p_t b)
  {
    return !(a == b);
  }
}

top::Dot::Dot(int x, int y):
  IDraw(), o{x,y}
{}
top::p_t top::Dot::begin() const
{
  return o;
}

top::p_t top::Dot::next() const
{
  return begin();
}

int main()
{
  int err = 0;
  top::IDraw * f[3] = {};
  top::p_t * p = nullptr;
  char * cnv = nullptr;
  size_t s = 0; 
  try {
    makeF(f,3);
    for (size_t i = 0; i < 3; ++i) {
      getPoints(f[i], &p, s);
    }
    top::Frame_t fr = top::build_frame(p, s);
    cnv = top::build_canvas(fr);
    top::paintCanvas(cnv, fr, p, s, '&');
    top::printCanvas(cnv, fr);
  } catch (...) {
    err = 1;
  }
  delete[] f[0];
  delete[] f[1];
  delete[] f[2];
  delete[] p;
  delete[] cnv;
  return err;
}
