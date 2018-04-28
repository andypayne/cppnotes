#include <iostream>
#include <random>

int main() {
  std::random_device seed{};
  std::mt19937 engine{seed()};
  // [1..10]
  std::uniform_int_distribution<> dist{1, 10};
  int x{ dist(engine) };
  std::cout << x << '\n';
}

