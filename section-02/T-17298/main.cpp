/*
 * Problem: 17298
 * URL: https://www.acmicpc.net/problem/17298
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int aSize = 0;

vector<int> a;
stack<int> aStack;
vector<int> o;

int main() {

  cin >> aSize;

  a.resize(aSize, 0);
  o.resize(aSize, -1);
  for (int aIndex = 0; aIndex < aSize; ++aIndex) {
    cin >> a[aIndex];

    while (aStack.size() && a[aStack.top()] < a[aIndex]) {
      o[aStack.top()] = a[aIndex];
      aStack.pop();
    }

    aStack.push(aIndex);
  }

  for (int oIndex = 0; oIndex < aSize; ++oIndex) {
    cout << o[oIndex] << ' ';
  }
  return 0;
}