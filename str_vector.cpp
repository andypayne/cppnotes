#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main() {
  vector<string> v{"Harold", "the rocks"};

  v.push_back("Coleco");
  v.push_back("Intellivision");

  cout << " Num elements: " << v.size() << '\n';
  cout << " Elements: ";
  for (string const& s : v) {
    cout << s << ' ';
  }
  cout << '\n';
  return 0;
}

