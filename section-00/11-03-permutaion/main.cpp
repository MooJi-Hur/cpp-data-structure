#include <bits/stdc++.h>

using namespace std;

void printValue(vector<int> inVector) {
  for (int i = 0; i < inVector.size(); i++) {
    cout << inVector[i] << ' ';
  }

  cout << endl;
}

int main() {
  int myArray[3] = {1, 2, 3};

  vector<int> myVector;

  for (int i = 0; i < 3; i++) myVector.push_back(myArray[i]);

  do {
    printValue(myVector);
  } while (next_permutation(myVector.begin(), myVector.end()));

  cout << endl;

  myVector.clear();

  for (int i = 2; i >= 0; i--) {
    myVector.push_back(myArray[i]);
  }

  do {
    printValue(myVector);
  } while (prev_permutation(myVector.begin(), myVector.end()));

  return 0;
}