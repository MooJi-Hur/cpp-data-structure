#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10;

char oneD[MAX_N];
int main() {
  memset(oneD, 'a', sizeof(oneD));

  for (int i = 0; i < 10; i++) {
    cout << oneD[i] << ' ';
  }

  cout << endl;

  return 0;
}