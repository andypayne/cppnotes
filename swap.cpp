#include <iostream>

void swap(int & a, int & b) {
  int temp{a};
  a = b;
  b = temp;
}

int main() {
  int x{2};
  int y{8};

  std::cout << "Before swap: x = " << x << "; y = " << y << '\n';
  swap(x, y);
  std::cout << "After swap: x = " << x << "; y = " << y << '\n';
  return 0;
}

