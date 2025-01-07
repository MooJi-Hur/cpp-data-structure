#include <bits/stdc++.h>

using namespace std;

vector<int> myVector;

int main() {
  for (int i = 1; i <= 5; i++) {
    myVector.push_back(i);
    myVector.push_back(i);
  }

  for (int i : myVector) cout << i << ' ';

  cout << endl;

  auto it = unique(myVector.begin(), myVector.end());

  cout << it - myVector.begin() << endl;

  for (int i : myVector) cout << i << ' ';

  cout << endl;

  return 0;
}