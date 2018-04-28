#include <iostream>

int main() {
  double fahrenheit{};
  double celsius{};

  std::cout << "Enter a temperature in Fahrenheit: ";
  std::cin >> fahrenheit;

  celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

  std::cout << "The value in Celsius is: " << celsius << "\n";
  return 0;
}

