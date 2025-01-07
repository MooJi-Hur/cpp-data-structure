#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> basicVector;

vector<vector<int>> initVector(10, vector<int>(10, 0));

vector<int> oneDVector[10];

void allocationByValue(vector<vector<int>> inVector) { inVector[0][0] = 10; }

void allocationByReference(vector<vector<int>> &inVector) {
  inVector[0][0] = 100;
}

void allocationByArrayValue(vector<int> inVector[10]) { inVector[0][0] = 1000; }

int main() {
  vector<int> last;

  last.push_back(0);

  basicVector.push_back(last);

  oneDVector[0].push_back(0);

  allocationByValue(basicVector);
  allocationByReference(initVector);
  allocationByArrayValue(oneDVector);

  cout << basicVector[0][0] << endl;
  cout << initVector[0][0] << endl;
  cout << oneDVector[0][0] << endl;

  return 0;
}