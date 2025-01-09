#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n) {
  cout << n << endl;

  if (n == 0 || n == 1) return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int n = 5;
int main() {
  cout << fibonacci(n) << endl;

  return 0;
}