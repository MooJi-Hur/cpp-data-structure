#include <bits/stdc++.h>

using namespace std;

int origin[5], cloned[5];

int main() {
  for (int i = 0; i < 5; i++) origin[i] = i;
  memcpy(cloned, origin, sizeof(origin));
  for (int i : cloned) cout << i << ' ';

  cout << endl;

  origin[4] = 1000;
  for (int i : origin) cout << i << ' ';

  cout << endl;

  memcpy(origin, cloned, sizeof(cloned));
  for (int i : origin) cout << i << ' ';

  cout << endl;
  return 0;
}