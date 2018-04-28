#include <iostream>

double CelsiusFromFahrenheit(double fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
  double fahrenheit{};
  std::cout << "Enter a temperature in Fahrenheit: ";
  std::cin >> fahrenheit;
  std::cout << "The value in Celsius is: " << CelsiusFromFahrenheit(fahrenheit) << "\n";
  return 0;
}

