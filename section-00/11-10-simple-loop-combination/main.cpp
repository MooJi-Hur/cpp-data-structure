#include <bits/stdc++.h>

using namespace std;

int n = 5, k = 2, candidates[5] = {1, 2, 3, 4, 5};

int main() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        cout << i << ' ' << j << ' ' << k << endl;
      }
    }
  }

  return 0;
}