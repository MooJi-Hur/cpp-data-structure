#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector{1, 2, 3, 4, 5};

  int sum = accumulate(myVector.begin(), myVector.end(), 0);

  cout << sum << endl;

  return 0;
}