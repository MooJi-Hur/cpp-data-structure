#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector = {1, 2, 3};

  int value = *max_element(myVector.begin(), myVector.end());
  auto it = max_element(myVector.begin(), myVector.end());
  int index = (int)(it - myVector.begin());

  cout << value << endl;
  cout << index << endl;
  return 0;
}