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

}


