#include <bits/stdc++.h>

using namespace std;

vector<int> myVector{1, 2, 3};

int main() {
  for (int myInt : myVector) cout << myInt << ' ';
  cout << endl;

  for (int i = 0; i < myVector.size(); i++) cout << myVector[i] << ' ';
  cout << endl;

  vector<pair<int, int>> myPairVector = {{1, 2}, {3, 4}};
  for (pair<int, int> myPair : myPairVector)
    cout << myPair.first << " : " << myPair.second << endl;
  return 0;
}