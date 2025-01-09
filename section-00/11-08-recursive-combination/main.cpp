#include <bits/stdc++.h>

using namespace std;

int n = 5, k = 3, candidates[5] = {1, 2, 3, 4, 5};

void show(vector<int> inVector) {
  for (int i : inVector) cout << i << ' ';
  cout << endl;
}

void combination(int start, vector<int> &inVector) {
  if (inVector.size() == k) {
    show(inVector);
    return;
  }

  for (int i = start + 1; i < n; i++) {
    inVector.push_back(i);
    combination(i, inVector);
    inVector.pop_back();
  }

  return;
}
int main() {
  vector<int> myVector;

  combination(-1, myVector);

  return 0;
}