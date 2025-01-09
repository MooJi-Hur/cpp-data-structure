#include <bits/stdc++.h>

using namespace std;

vector<int> myVector;

int main() {
  int n = 100, b = 2;

  while (n > 1) {
    myVector.push_back(n % b);
    n /= b;
  }

  if (n == 1) myVector.push_back(1);

  reverse(myVector.begin(), myVector.end());

  for (int a : myVector) {
    if (a >= 10)
      cout << char(a + 55);
    else
      cout << a;
  }

  return 0;
}