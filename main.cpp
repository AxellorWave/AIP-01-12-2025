#include <iostream>

namespace top {
  struct p_t {
    int x, y;
  };

  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
  };

  struct Dot: IDraw {
    Dot(int x, int y);
    Dot(p_t p);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t o;
  };

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

  struct frame_t {
    p_t leftBot, rightTop;
  };

  void make_f(IDraw ** b, size_t k);
  void get_points(IDraw * b, p_t ** ps, size_t & s);
  frame_t build_frame(const p_t * ps, size_t s);
  char * build_canvas(frame_t f);
  void paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f);
  void print_canvas(const char * cnv, frame_t fr);
  bool operator==(p_t a, p_t b)
  {
    return a.x == b.x && a.y == b.y;
  }
  
  bool operator!=(p_t a, p_t b)
  {
    return !(a == b);
  }
}

int main()
{
  int err = 0;
  top::IDraw * f[3] = {};
  top::p_t * p = nullptr;
  char * cnv = nullptr;
  size_t s = 0; 
  try {
    make_f(f,3);
    for (size_t i = 0; i < 3; ++i) {
      get_points(f[i], &p, s);
    }
    top::frame_t fr = top::build_frame(p, s);
    cnv = top::build_canvas(fr);
    top::paint_canvas(cnv, fr, p, s, '&');
    top::print_canvas(cnv, fr);
  } catch (...) {
    err = 1;
  }
  delete f[0];
  delete f[1];
  delete f[2];
  delete[] p;
  delete[] cnv;
  return err;
}

top::Dot::Dot(int x, int y):
  IDraw(), 
  o{x,y}
{}
top::p_t top::Dot::begin() const
{
  return o;
}

top::p_t top::Dot::next(p_t p) const
{
  return begin();
}

top::Dot::Dot(int x, int y):
  IDraw(),
  o{x, y}
{}

top::Dot::Dot(p_t p):
  IDraw(), 
  o(p)
{}

top::p_t top::Dot::begin() const
{
  return o;
}

top::p_t top::Dot::next(p_t p) const
{
  return begin();
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

top::Vline::Vline(p_t p, int l)
{
  Vline(p.x, p.y, l);
}

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

top::Hline::Hline(p_t p, int l)
{
  Hline(p.x, p.y, l);
}

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

void top::make_f(IDraw ** b, size_t k)
{
  b[0] = new Dot(0, 0);
  b[1] = new Dot(-1, -5);
  b[2] = new Dot(7, 7);
}

void top::get_points(IDraw * b, p_t ** ps, size_t & s)
{
  p_t a = b->begin();
  // Достать точки
  // Сгенерировать точки
  // Положить в ps (обновить массив)
  // Обновить размер
}

top::frame_t top::build_frame(const p_t * ps, size_t s)
{
  // Найти min и max для x и y
  // Сформировать frame_t
}

char * top::build_canvas(frame_t f)
{
  // Посчитать кол-во колонок и строк (max - min + 1)
}

void top::paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f)
{
  // Перевести в другие координаты
}

void top::print_canvas(const char * cnv, frame_t fr)
{
  // std::cout
}
