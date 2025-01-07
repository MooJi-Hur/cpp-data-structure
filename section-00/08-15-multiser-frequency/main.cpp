#include <bits/stdc++.h>

using namespace std;

int main() {
  multiset<int> numbers = {1, 2, 3, 3, 4, 5, 5, 5, 6};

  int countFive = numbers.count(5);

  cout << countFive << endl;

  return 0;
}