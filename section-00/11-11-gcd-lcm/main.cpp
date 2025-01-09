#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int main() {
  int first = 10, second = 12;

  cout << gcd(first, second) << endl;
  cout << lcm(first, second) << endl;

  return 0;
}