#include <iostream>

int main() {
  int a{2};
  int b{3};

  std::cout << a << " * " << b << " = ? ";

  int userAnswer{};
  std::cin >> userAnswer;

  if (userAnswer == (a * b)) {
    std::cout << "Correct!\n";
  } else {
    std::cout << "Wrong!\n";
  }
  return 0;
}

