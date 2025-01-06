#include <bits/stdc++.h>

using namespace std;

int i;

string myHello = "Hello";

int main() {
  i = 0;

  int* a = &i;
  cout << a << endl;

  string* b = &myHello;
  cout << b << endl;

  return 0;
}