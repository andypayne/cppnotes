#include <iostream>
#include <string>

int main() {
  std::cout << "What's your name? ";
  std::string name{};
  std::cin >> name;

  std::cout << '\n';
  std::cout << "Hi, " << name << "!\n";
  std::cout << "Nice to meet you!\n";
  return 0;
}

