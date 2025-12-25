#include <iostream>

void hi()
{
  std::cout << "< Hi! >\n";
}

int main()
{
  size_t i = 0;
  while (!(std::cin >> i).eof()) {
    if (i == 0) {
      hi();
    } else {
      std::cerr << "< INVALID >\n";
    }
  }
  
}
