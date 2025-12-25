#include <iostream>
#include <cassert>

void hi()
{
  std::cout << "< Hi! >\n";
}

bool is_space(char c)
{
  return std::isspace(c);
}

std::istream& getword(std::istream& is, char * word, size_t k, bool(*c)(char))
{
  assert(k > 0 && "k must be greater than 0");
  if (!k || !word) {
    throw std::logic_error("bad buffer size");
  }
  is >> std::noskipws;
  size_t i = 0;
  for (char next = 0; is && !c(next) && (i < k - 1); ++i) {
    is >> next;
    word[i] = next;
  }
  if (i == k) {
    is.clear(is.rdstate() | std::ios::failbit);
  }
  return is >> std::skipws;
}

size_t match(const char * word , const char * const * words, size_t k);

int main()
{
  constexpr size_t cmds_counts = 1;
  void(*cmds[1])() = {hi};
  const char * const cmds_text[] = {"hi"};
  constexpr size_t bsize = 255;
  char word[bsize + 1] = {};
  while (!getword(std::cin, word, bsize, is_space)) {
    if (std::cin.fail()) {
      std::cerr << "< INVALID INPUT >\n";
      return 1;
    } else if (size_t i = match(word, cmds_text, cmds_counts); i < cmds_counts) {
      cmds[i]();
    } else {
      std::cerr << "< INVALID COMMAND >\n";
    }
  }
  
}
