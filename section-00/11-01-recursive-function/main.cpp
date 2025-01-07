#include <bits/stdc++.h>

using namespace std;

int factorialRecursive(int n) {
  if (n == 1 || n == 0) return 1;

  return n * factorialRecursive(n - 1);
}

int factorialLoop(int n) {
  int result = 1;

  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

int n = 5;

int main() {
  cout << factorialRecursive(n) << endl;

  cout << factorialLoop(n) << endl;

  return 0;
}