#include <iostream>
#include <string>

void underline(std::string const& s) {
  std::string line(s.length(), '=');

  std::cout << s << '\n';
  std::cout << line << '\n';
}

int main() {
  std::cout << "Enter a string: ";
  std::string str{};
  std::cin >> str;
  std::cout << '\n';
  underline(str);
  return 0;
}

