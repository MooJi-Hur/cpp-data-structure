#include <bits/stdc++.h>

using namespace std;

vector<int> myVector;

int main() {
  for (int i = 1; i <= 10; i++) myVector.push_back(i);

  for (int myInt : myVector) cout << myInt << ' ';
  cout << endl;

  myVector.pop_back();

  for (int myInt : myVector) cout << myInt << ' ';
  cout << endl;

  myVector.erase(myVector.begin(), myVector.begin() + 3);

  for (int myInt : myVector) cout << myInt << ' ';
  cout << endl;

  auto found = find(myVector.begin(), myVector.end(), 100);
  if (found == myVector.end()) cout << "Not Found." << endl;

  fill(myVector.begin(), myVector.end(), 10);

  for (int myInt : myVector) cout << myInt << ' ';
  cout << endl;

  myVector.clear();

  for (int myInt : myVector) cout << myInt << ' ';

  cout << endl;

  return 0;
}