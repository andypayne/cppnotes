#include <iostream>

int main() {
  // Print boolean values as true/false instead of 1/0
  std::cout << std::boolalpha;

  double x1 = 0.3;
  double x2 = 0.1 + 0.1 + 0.1;

  std::cout << "x1 == x2 : " << (x1 == x2) << '\n';

  double y1 = 0.5;
  double y2 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

  std::cout << "y1 == y2 : " << (y1 == y2) << '\n';

  return 0;
}

