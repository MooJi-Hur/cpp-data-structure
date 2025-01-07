#include <bits/stdc++.h>

using namespace std;

multiset<int> myMultiset;

int main() {
  for (int i = 5; i >= 1; i--) {
    myMultiset.insert(i);
    myMultiset.insert(i);
  }

  for (int it : myMultiset) cout << it << ' ';

  cout << endl;

  return 0;
}