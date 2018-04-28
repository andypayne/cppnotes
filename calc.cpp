#include <iostream>

int main() {
  std::cout << " a = ? ";
  int a{};
  std::cin >> a;

  std::cout << " b = ? ";
  int b{};
  std::cin >> b;

  std::cout << "\n";
  std::cout << " a + b = " << (a + b) << "\n";
  std::cout << " a - b = " << (a - b) << "\n";
  std::cout << " a * b = " << (a * b) << "\n";
  std::cout << " a / b = " << (a / b) << "\n";
  std::cout << " a % b = " << (a % b) << "\n";
}



