#include <bits/stdc++.h>

using namespace std;

vector<int> myVector{1, 2, 3, 3, 4, 100};

int main() {
  cout << *lower_bound(myVector.begin(), myVector.end(), 100) << endl;

  return 0;
}