#include <iostream>

using std::cout;


class c1
{
private:
  int x;

public:
  c1() = default;
  void method() { x = 0; }
};

class c2
{
private:
  int x;

public:
  c2() = default;
  virtual void method() { x = 0; }
};

int main()
{
  c1 c1i{};
  c2 c2i{};

  cout << "sizeof(c1) = " << sizeof(c1) << '\n';
  cout << "sizeof(c2) = " << sizeof(c2) << '\n';
  cout << "sizeof(cl1i) = " << sizeof(c1i) << '\n';
  cout << "sizeof(c2i) = " << sizeof(c2i) << '\n';
  return 0;
}

