#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string s{"Connie"};
  std::string su;
  // Or char c
  for (auto c : s) {
    su += std::toupper(c);
  }
  std::cout << s << " --upper--> " << su << "\n";
  return 0;
}

