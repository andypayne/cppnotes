#include <iostream>


int main()
{
  int i = 10;
  std::cout << typeid(decltype(i + 1.0)).name() << std::endl;
}

