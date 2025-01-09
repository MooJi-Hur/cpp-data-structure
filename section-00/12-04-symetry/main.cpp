#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> myVector = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << myVector[j][i] << ' ';
    }

    cout << endl;
  }

  return 0;
}