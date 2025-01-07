#include <bits/stdc++.h>

using namespace std;

vector<int> myVector(3, 0);

void go(vector<int> inVector) { inVector[1] = 100; }

int main() {
  go(myVector);

  for (int i : myVector) cout << i << endl;

  return 0;
}