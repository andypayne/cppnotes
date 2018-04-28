#include <iostream>
#include <string>

int main() {
  std::cout << "Message? ";
  std::string msg{};
  std::getline(std::cin, msg);

  std::string flowerLine(msg.length() + 4, '*');

  std::cout << '\n';
  std::cout << flowerLine << '\n';
  std::cout << "* " << msg << " *\n";
  std::cout << flowerLine << '\n';

  return 0;
}

