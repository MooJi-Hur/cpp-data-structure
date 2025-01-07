#include <bits/stdc++.h>

using namespace std;

int first[3] = {1, 2, 3};
int second[] = {1, 2, 3, 4};
int third[10];

int main() {
  for (int i = 0; i < 3; i++) cout << first[i] << ' ';
  cout << endl;
  for (int i : first) cout << i << ' ';
  cout << endl;

  for (int i = 0; i < 4; i++) cout << second[i] << ' ';
  cout << endl;
  for (int i : second) cout << i << ' ';
  cout << endl;

  for (int i = 0; i < 10; i++) third[i] = i;

  for (int i : third) cout << i << ' ';
  cout << endl;

  return 0;
}