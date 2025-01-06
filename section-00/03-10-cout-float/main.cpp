#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double myDouble = 1.23456789;

int main() {
  cout << myDouble << endl;  // 1.23457, 6이 아니라 7
  cout << fixed << setprecision(3) << myDouble << endl;
  cout << fixed << setprecision(8) << myDouble << endl;

  return 0;
}