#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> beforeInitVector;
vector<vector<int>> initAllVector;
vector<int> beforeInitInnerVector;

int main() {
  for (int i = 0; i < 10; i++) {
    vector<int> innerVector;
    beforeInitVector.push_back(innerVector);
  }

  return 0;
}