#include <bits/stdc++.h>

using namespace std;

pair<int, int> myPair;
tuple<int, int, int> myTuple;

int a, b, c;

int main() {
  myPair = {1, 2};

  a = myPair.first;
  b = myPair.second;

  cout << a << " : " << b << endl;

  myTuple = make_tuple(1, 2, 3);

  a = get<0>(myTuple);
  b = get<1>(myTuple);
  c = get<2>(myTuple);

  cout << a << " : " << b << " : " << c << endl;

  return 0;
}