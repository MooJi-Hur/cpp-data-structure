#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) { return a < b; }

vector<int> myVector = {3, 10, 4, 11};

int main() {
  sort(myVector.begin(), myVector.end(), cmp);

  for (int i : myVector) cout << i << endl;

  return 0;
}