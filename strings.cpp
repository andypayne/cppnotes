#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
  std::string s1("hello:there:it's:me");

  std::cout << "s1 = " << s1 << '\n';
  if (s1.find(':') != std::string::npos) {
    std::cout << "s1.find = " << s1.find(':') << '\n';
    std::cout << "First value = [" << s1.substr(0, s1.find(':')) << "]\n";
  } else {
    std::cout << ": not found\n";
  }

  return 0;
}

