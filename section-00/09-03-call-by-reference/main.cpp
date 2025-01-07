#include <bits/stdc++.h>

using namespace std;

int add(int &a, int &b) {
  a += 10;

  cout << a << endl;  // 11

  return a + b;
}

int main() {
  int one = 1;
  int two = 2;

  int sum = add(one, two);

  cout << one << endl;  // 11
  cout << sum << endl;  // 11 + 2 = 13

  return 0;
}