#include <bits/stdc++.h>

using namespace std;

pair<int, int> myPair;
tuple<int, int, int> myTuple;

int a, b, c;
int main() {
  myPair = {1, 2};  // make_pair(1, 2);도 가능
  myTuple = make_tuple(1, 2, 3);

  tie(a, b) = myPair;
  cout << a << " : " << b << endl;

  tie(a, b, c) = myTuple;

  cout << a << " : " << b << " : " << c << endl;

  return 0;
}