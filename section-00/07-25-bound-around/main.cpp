#include <bits/stdc++.h>

using namespace std;

vector<int> myVector;

int main() {
  for (int i = 2; i <= 5; i++) myVector.push_back(i);

  myVector.push_back(7);
  // 2 3 4 5 7
  // 0 1 2 3 4

  cout << upper_bound(myVector.begin(), myVector.end(), 6) - myVector.begin()
       << endl;
  cout << lower_bound(myVector.begin(), myVector.end(), 6) - myVector.begin()
       << endl;
  cout << upper_bound(myVector.begin(), myVector.end(), 9) - myVector.begin()
       << endl;
  cout << lower_bound(myVector.begin(), myVector.end(), 9) - myVector.begin()
       << endl;
  cout << upper_bound(myVector.begin(), myVector.end(), 0) - myVector.begin()
       << endl;
  cout << lower_bound(myVector.begin(), myVector.end(), 0) - myVector.begin()
       << endl;

  return 0;
}