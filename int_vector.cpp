#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<int> v{1980, 1995, 2005, 2016};

  v.push_back(64);
  v.push_back(500);

  cout << " Number of elements: " << v.size() << '\n';
  cout << " Elements: ";
  for (int n : v) {
    cout << n << ' ';
  }
  cout << '\n';
  return 0;
}

