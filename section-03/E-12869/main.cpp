/*
 * Problem: 12869
 * URL: https://www.acmicpc.net/problem/12869
 */

#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// in
int svcSize;
constexpr int MAX_SVC_COUNT = 3;
array<int, MAX_SVC_COUNT> svcs = {0};

// out
int minAttackCount;

// logic
typedef struct SVC {
  int firstSVC;
  int secondSVC;
  int thirdSVC;
  int currentLevel = 0;

  int getSum() { return firstSVC + secondSVC + thirdSVC; }
} SVC;

constexpr int ORDER_SIZE = 6;
array<int, MAX_SVC_COUNT> attackOrders[ORDER_SIZE] = {
    {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

bool visited[61][61][61] = {false};

void readSvc() {
  cin >> svcSize;
  for (int svcIndex = 0; svcIndex < svcSize; ++svcIndex) {
    cin >> svcs[svcIndex];
  }
}

void calcSvc() {
  queue<SVC> bfsQueue;
  int firstSVC = svcs[0], secondSVC = svcs[1], thirdSVC = svcs[2];
  bfsQueue.push(SVC{firstSVC, secondSVC, thirdSVC, 0});
  visited[firstSVC][secondSVC][thirdSVC] = true;

  while (!bfsQueue.empty()) {
    SVC currentSvc = bfsQueue.front();
    bfsQueue.pop();

    bool isAllKilled = currentSvc.getSum() == 0;

    if (isAllKilled) {
      minAttackCount = currentSvc.currentLevel;
      return;
    }

    for (int orderIndex = 0; orderIndex < ORDER_SIZE; ++orderIndex) {

      int nextFirstSvc =
          max(0, currentSvc.firstSVC - attackOrders[orderIndex][0]);

      int nextSecondSvc =
          max(0, currentSvc.secondSVC - attackOrders[orderIndex][1]);

      int nextThirdSvc =
          max(0, currentSvc.thirdSVC - attackOrders[orderIndex][2]);

      if (visited[nextFirstSvc][nextSecondSvc][nextThirdSvc])
        continue;

      visited[nextFirstSvc][nextSecondSvc][nextThirdSvc] = true;

      SVC nextSVC = SVC{nextFirstSvc, nextSecondSvc, nextThirdSvc,
                        currentSvc.currentLevel + 1};

      bfsQueue.push(nextSVC);
    }
  }
}

int main() {

  readSvc();

  calcSvc();

  cout << minAttackCount;

  return 0;
}