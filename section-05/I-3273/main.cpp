/*
 * Problem: 3273
 * URL: https://www.acmicpc.net/problem/3273
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int inSize, inSum;
vector<int> inOperands;
set<int> targetOperands;

int pairCount;

void read() {
  cin >> inSize;
  inOperands.resize(inSize);
  for (auto &inOperand : inOperands) {
    cin >> inOperand;
    targetOperands.insert(inOperand);
  }
  cin >> inSum;
}

void calc() {
  for (int currentIndex = 0; currentIndex < inSize; ++currentIndex) {
    int currentOperand = inOperands[currentIndex];
    targetOperands.erase(currentOperand);
    int targetInt = inSum - currentOperand;

    auto targetIt = targetOperands.find(targetInt);

    if (targetIt == targetOperands.end()) {
      continue;
    }

    pairCount++;
  }
}

int main() {

  read();

  calc();

  cout << pairCount;

  return 0;
}