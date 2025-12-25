#include <iostream>

void hi()
{
  std::cout << "< Hi! >\n";
}

int main()
{
  constexpr size_t cmds_counts = 1;
  void(*cmds[1])() = {hi};
  size_t i = 0;
  while (!(std::cin >> i).eof()) {
    if (std::cin.fail()) {
      std::cerr << "< INVALID INPUT >\n";
      return 1;
    } else if (i < cmds_counts) {
      cmds[i]();
    } else {
      std::cerr << "< INVALID COMMAND >\n";
    }
  }
  
}
