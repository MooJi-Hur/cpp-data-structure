#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector{1, 2, 3, 3, 3, 4};
  cout << lower_bound(myVector.begin(), myVector.end(), 3) - myVector.begin()
       << endl;

  cout << upper_bound(myVector.begin(), myVector.end(), 3) - myVector.begin()
       << endl;

  return 0;
}