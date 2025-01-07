#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> myVector = {1, 2, 3};
  int value = *min_element(myVector.begin(), myVector.end());
  auto it = min_element(myVector.begin(), myVector.end());
  int index = (int)(it - myVector.begin());

  cout << value << endl;
  cout << index << endl;

  return 0;
}