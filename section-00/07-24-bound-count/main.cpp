#include <bits/stdc++.h>

using namespace std;

vector<int> myVector{1, 2, 3, 3, 3, 3, 4};

int main() {
  cout << upper_bound(myVector.begin(), myVector.end(), 3) -
              lower_bound(myVector.begin(), myVector.end(), 3)
       << endl;

  return 0;
}