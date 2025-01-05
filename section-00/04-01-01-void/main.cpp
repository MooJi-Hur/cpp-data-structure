#include <bits/stdc++.h>

using namespace std;

int ret = 1;

void myVoidFunction() {
  ret = 2;

  cout << ret << endl;

  return;
}

int main() {
  myVoidFunction();

  return 0;
}