#include <bits/stdc++.h>

using namespace std;

int myArray[5];
vector<int> myVector;

int main() {
  for (int i = 5; i >= 1; i--) myArray[i - 1] = i;
  for (int i = 5; i >= 1; i--) myVector.push_back(i);

  sort(myArray, myArray + 5);
  sort(myVector.begin(), myVector.end());

  for (int i : myArray) cout << i << ' ';
  cout << endl;

  for (int i : myVector) cout << i << ' ';
  cout << endl;

  // less
  sort(myArray, myArray + 5, less<int>());
  sort(myVector.begin(), myVector.end(), less<int>());

  for (int i : myArray) cout << i << ' ';
  cout << endl;

  for (int i : myVector) cout << i << ' ';
  cout << endl;

  // greater
  sort(myArray, myArray + 5, greater<int>());
  sort(myVector.begin(), myVector.end(), greater<int>());

  for (int i : myArray) cout << i << ' ';
  cout << endl;

  for (int i : myVector) cout << i << ' ';

  return 0;
}