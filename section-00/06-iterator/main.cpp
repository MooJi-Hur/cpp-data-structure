#include <bits/stdc++.h>

using namespace std;

vector<int> myVector;
int main() {
  for (int i = 0; i <= 5; i++) myVector.push_back(i);

  cout << endl;

  for (int i = 0; i < 5; i++) {
    cout << i << " : " << *(myVector.begin() + i) << endl;
    cout << &*(myVector.begin() + i) << endl;
  }

  cout << endl;

  for (auto it = myVector.begin(); it != myVector.end(); it++) {
    cout << *it << endl;
  }

  cout << endl;

  for (vector<int>::iterator it = myVector.begin(); it != myVector.end();
       it++) {
    cout << *it << endl;
  }

  auto it = myVector.begin();

  advance(it, 3);

  cout << endl;

  cout << *it << endl;

  return 0;
}