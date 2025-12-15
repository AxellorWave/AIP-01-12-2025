#include <iostream>
#include "geom.hpp"
#include "idraw.hpp"
#include "dot.hpp"

namespace top {
  struct Vline: IDraw {
    Vline(int x, int y, int l);
    Vline(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

  struct Hline: IDraw {
    Hline(int x, int y, int l);
    Hline(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

  struct Dline: IDraw {
    Dline(int x, int y, int l);
    Dline(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

  struct Rectangle: IDraw {
    Rectangle(int x, int y, int a, int b);
    Rectangle(p_t p, int a, int b);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int a_, b_;
  };

  struct RectangleFilled: IDraw {
    RectangleFilled(int x, int y, int a, int b);
    RectangleFilled(p_t p, int a, int b);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int a_, b_;
  };

  struct Square: IDraw {
    Square(int x, int y, int l);
    Square(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

  struct SquareFilled: IDraw {
    SquareFilled(int x, int y, int l);
    SquareFilled(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

  void make_f(IDraw ** b, size_t k);
  frame_t build_frame(const p_t * ps, size_t s);
  char * build_canvas(frame_t f, char fill);
  void paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f);
  void print_canvas(std::ostream & os, const char * cnv, frame_t fr);
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
    make_f(f,size);
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

top::Vline::Vline(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len == 0) {
    throw std::invalid_argument("lenght can not be 0");
  }
  if (len < 0) {
    len *= -1;
    start.y -= len;
  }
}

top::Vline::Vline(p_t p, int l):
  Vline(p.x, p.y, l)
{}

top::p_t top::Vline::begin() const
{
  return start;
}

top::p_t top::Vline::next(p_t p) const
{
  if (p.y == start.y + len - 1) {
    return start;
  }
  return {p.x, p.y + 1};
}

top::Hline::Hline(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len == 0) {
    throw std::invalid_argument("lenght can not be 0");
  }
  if (len < 0) {
    len *= -1;
    start.x -= len;
  }
}

top::Hline::Hline(p_t p, int l):
  Hline(p.x, p.y, l)
{}

top::p_t top::Hline::begin() const
{
  return start;
}

top::p_t top::Hline::next(p_t p) const
{
  if (p.x == start.x + len - 1) {
    return start;
  }
  return {p.x + 1, p.y};
}

top::Dline::Dline(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len == 0) {
    throw std::invalid_argument("lenght can not be 0");
  }
  if (len < 0) {
    len *= -1;
    start.y -= len;
  }
}

top::Dline::Dline(p_t p, int l):
  Dline(p.x, p.y, l)
{}

top::p_t top::Dline::begin() const
{
  return start;
}

top::p_t top::Dline::next(p_t p) const
{
  if (p.y == start.y + len - 1) {
    return start;
  }
  return {p.x + 1, p.y + 1};
}

top::Rectangle::Rectangle(int x, int y, int a, int b):
  IDraw(),
  start{x, y},
  a_(a),
  b_(b)
{
  if (a_ <= 0 || b_ <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::Rectangle::Rectangle(p_t p, int a, int b):
  Rectangle(p.x, p.y, a, b)
{}

top::p_t top::Rectangle::begin() const
{
  return start;
}

top::p_t top::Rectangle::next(p_t p) const
{
  if (p.x == start.x && p.y < start.y + a_ - 1) {
    return {p.x, p.y + 1};
  }
  if (p.y == start.y + a_ - 1 && p.x < start.x + b_ - 1) {
    return {p.x + 1, p.y};
  }
  if (p.x == start.x + b_ - 1 && p.y > start.y) {
    return {p.x, p.y - 1};
  }
  if (p.y == start.y && p.x > start.x) {
    return {p.x - 1, p.y};
  }
  return start;
}

top::RectangleFilled::RectangleFilled(int x, int y, int a, int b):
  IDraw(),
  start{x, y},
  a_(a),
  b_(b)
{
  if (a_ <= 0 || b_ <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::RectangleFilled::RectangleFilled(p_t p, int a, int b):
  RectangleFilled(p.x, p.y, a, b)
{}

top::p_t top::RectangleFilled::begin() const
{
  return start;
}

top::p_t top::RectangleFilled::next(p_t p) const
{
  if (p.x < start.x + b_ - 1) {
    return {p.x + 1, p.y};
  } else if (p.y < start.y + a_ - 1) {
    return {start.x, p.y + 1};
  }
  return start;
}

top::Square::Square(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::Square::Square(p_t p, int l):
  Square(p.x, p.y, l)
{}

top::p_t top::Square::begin() const
{
  return start;
}

top::p_t top::Square::next(p_t p) const
{
  if (p.x == start.x && p.y < start.y + len - 1) {
    return {p.x, p.y + 1};
  }
  if (p.y == start.y + len - 1 && p.x < start.x + len - 1) {
    return {p.x + 1, p.y};
  }
  if (p.x == start.x + len - 1 && p.y > start.y) {
    return {p.x, p.y - 1};
  }
  if (p.y == start.y && p.x > start.x) {
    return {p.x - 1, p.y};
  }
  return start;
}

top::SquareFilled::SquareFilled(int x, int y, int l):
  IDraw(),
  start{x, y},
  len(l)
{
  if (len <= 0) {
    throw std::invalid_argument("lenght can not be <= 0");
  }
}

top::SquareFilled::SquareFilled(p_t p, int l):
  SquareFilled(p.x, p.y, l)
{}

top::p_t top::SquareFilled::begin() const
{
  return start;
}

top::p_t top::SquareFilled::next(p_t p) const
{
  if (p.x < start.x + len - 1) {
    return {p.x + 1, p.y};
  } else if (p.y < start.y + len - 1) {
    return {start.x, p.y + 1};
  }
  return start;
}

void top::make_f(IDraw ** b, size_t k)
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

top::frame_t top::build_frame(const p_t * ps, size_t s)
{
  if (!s) {
    throw std::logic_error("");
  }
  int minx = ps[0].x, maxx = ps[0].x;
  int miny = ps[0].y, maxy = ps[0].y;
  for (size_t i = 1; i < s; ++i) {
    minx = std::min(minx, ps[i].x);
    maxx = std::max(maxx, ps[i].x);
    miny = std::min(miny, ps[i].y);
    maxy = std::max(maxy, ps[i].y);
  }
  p_t aa {minx, miny};
  p_t bb { maxx, maxy};
  return {aa, bb};
}

char * top::build_canvas(frame_t f, char fill)
{
  char * cnv =  new char[rows(f) * cols(f)];
  for (size_t i = 0; i < rows(f) * cols(f); ++i) {
    cnv[i] = fill; 
  }
  return cnv;
}

void top::paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f)
{
  for (size_t i = 0; i < k; ++i) {
    int dx = ps[i].x - fr.leftBot.x;
    int dy = fr.rightTop.y - ps[i].y;
    cnv[dy * cols(fr) + dx] = f;
  }
  
}

void top::print_canvas(std::ostream & os, const char * cnv, frame_t fr)
{
  for (size_t i = 0; i < rows(fr); ++i) {
    for (size_t j = 0; j < cols(fr); ++j) {
      os << cnv[i * cols(fr) + j];
    }
    os << "\n";
  }
}
