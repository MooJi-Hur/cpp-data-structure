#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector{1, 2, 3, 3, 3, 4};

  cout << &*lower_bound(myVector.begin(), myVector.end(), 3) << endl;
  cout << &*myVector.begin() << endl;
  cout << &*(myVector.begin() + 1) << endl;
  cout << &*(myVector.begin() + 2) << endl;

  return 0;
}