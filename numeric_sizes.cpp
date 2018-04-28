#include <iostream>
#include <limits>


int main() {
  std::cout << "short type\n";
  std::cout << "--------\n";
  std::cout << "sizeof(short) = " << sizeof(short) << " bytes\n";
  std::cout << "max short     = " << std::numeric_limits<short>::max() << '\n';
  std::cout << "min short     = " << std::numeric_limits<short>::min() << '\n';

  std::cout << "\n\n";
  std::cout << "int type\n";
  std::cout << "--------\n";
  std::cout << "sizeof(int) = " << sizeof(int) << " bytes\n";
  std::cout << "max int     = " << std::numeric_limits<int>::max() << '\n';
  std::cout << "min int     = " << std::numeric_limits<int>::min() << '\n';

  std::cout << "\n\n";
  std::cout << "long type\n";
  std::cout << "--------\n";
  std::cout << "sizeof(long) = " << sizeof(long) << " bytes\n";
  std::cout << "max long     = " << std::numeric_limits<long>::max() << '\n';
  std::cout << "min long     = " << std::numeric_limits<long>::min() << '\n';
}


