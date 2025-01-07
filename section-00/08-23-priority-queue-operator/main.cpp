#include <bits/stdc++.h>

using namespace std;

class Adder {
 public:
  int operator()(int a, int b) { return a + b; }
};

int main() {
  Adder adder;

  cout << adder(3, 4);

  return 0;
}