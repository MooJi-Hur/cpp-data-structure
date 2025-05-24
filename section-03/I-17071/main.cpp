/*
 * Problem: 17071
 * URL: https://www.acmicpc.net/problem/17071
 */

#include <array>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

// in
int startPoint = 0, endPoint = 0;

// out
constexpr int OUT_OF_RESULT = -1;
constexpr int MAX_POSITION = 500000;
int timeCount = 0;

// logic
array<int, MAX_POSITION + 1> levelCounts;
vector<int> endPoints;

void initPositions() { cin >> startPoint >> endPoint; };

void fillEndCandidates() {
  int prevPoint = 0;
  for (int addPoint = 1; endPoint <= 500000; ++addPoint) {
    prevPoint += addPoint;
    endPoints.push_back(endPoint + prevPoint);
  }

  for (auto cell : endPoints) {
    cout << cell << '\n';
  }
};

void findGoal() {
  queue<int> bfsQueue;

  bfsQueue.push(startPoint);

  while (!bfsQueue.empty() && endPoint <= MAX_POSITION) {
    int currentPoint = bfsQueue.front();
    bfsQueue.pop();

    if (currentPoint == endPoint) {
      return;
    }

    bool isOutPoint = currentPoint < 0 || currentPoint > MAX_POSITION ||
                      endPoint > MAX_POSITION;
    if (isOutPoint) {
      timeCount = 0;
      return;
    }

    for (int nextPoint :
         {currentPoint - 1, currentPoint + 1, currentPoint * 2}) {

      bool isInBound = nextPoint >= 0 && nextPoint <= MAX_POSITION;

      if (isInBound) {
        bool needRevisit = nextPoint >= endPoint && levelCounts[nextPoint] != 0;
        bool canMoveNext = levelCounts[nextPoint] == 0;

        if (needRevisit || canMoveNext) {
          bfsQueue.push(nextPoint);
        }

        if (canMoveNext) {
          bfsQueue.push(nextPoint);
          levelCounts[nextPoint] = levelCounts[currentPoint] + 1;
        }
      }
    }

    if (timeCount < levelCounts[currentPoint]) {
      timeCount = levelCounts[currentPoint];
      endPoint += timeCount;
    }
  }
};

void printResult() {
  bool isOutOfResult = timeCount == 0 || endPoint > MAX_POSITION;

  if (startPoint == endPoint) {
    cout << 0;
  } else if (isOutOfResult) {
    cout << OUT_OF_RESULT;
  } else {
    cout << timeCount;
  }
};

int main() {

  initPositions();

  fillEndCandidates();

  findGoal();

  printResult();

  return 0;
}