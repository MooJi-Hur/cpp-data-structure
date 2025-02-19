/*
 * Problem: 12851
 * URL: https://www.acmicpc.net/problem/12851
 */

// #include "timer.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

constexpr int PATH_START = 0;
constexpr int PATH_FINISH = 100000;
constexpr int PATH_SIZE = 1 + PATH_FINISH;

typedef struct Node {
  int data;
  int level;
  Node *parent;
  Node *minusOne;
  Node *plusOne;
  Node *twoTimes;

  Node()
      : data(-1), level(0), parent(NULL), minusOne(NULL), plusOne(NULL),
        twoTimes(NULL) {}
} Node;

void readInitPoints(int &startPoint, int &endPoint);
Node *buildHeader(const int startPoint);

void findGoal(int &endPoint,
              int &shortestLevels,
              int &shortestCount,
              Node *header);

void getShortInfos(int &shortestLevels, int &shortestCount);

int main() {

  int startPoint = 0;
  int endPoint = 0;

  int shortestLevels = 0;
  int shortestCount = 0;
  readInitPoints(startPoint, endPoint);

  Node *header = buildHeader(startPoint);

  findGoal(endPoint, shortestLevels, shortestCount, header);

  getShortInfos(shortestLevels, shortestCount);

  return 0;
}

void readInitPoints(int &startPoint, int &endPoint) {
  cin >> startPoint >> endPoint;
}

Node *buildHeader(const int startPoint) {
  Node *header = new Node();
  header->data = startPoint;
  return header;
}

void findGoal(int &endPoint,
              int &shortestLevels,
              int &shortestCount,
              Node *header) {

  queue<Node *> bfsQueue;

  bfsQueue.push(header);
  if (header->data == endPoint) {
    shortestLevels = 1;
    shortestCount++;
    return;
  }

  while (!bfsQueue.empty()) {
    Node currentNode = *bfsQueue.front();
    int currentData = currentNode.data;
    int nextLevel = currentNode.level + 1;

    bfsQueue.pop();

    if (shortestCount == 1) {
      shortestLevels = currentNode.level;
    }

    if (currentData == endPoint) {
      if ((shortestCount != 0) && (shortestLevels < currentNode.level)) {
        break;
      }
      shortestCount++;
    }

    if (!shortestLevels && currentData != endPoint) {

      Node *minusOneNode = new Node();
      minusOneNode->data = currentData - 1;
      minusOneNode->level = nextLevel;
      currentNode.minusOne = minusOneNode;

      Node *plusOneNode = new Node();
      plusOneNode->data = currentData + 1;
      plusOneNode->level = nextLevel;
      currentNode.plusOne = plusOneNode;

      Node *twoTimesNode = new Node();
      twoTimesNode->data = currentData * 2;
      twoTimesNode->level = nextLevel;
      currentNode.twoTimes = twoTimesNode;

      bfsQueue.push(currentNode.minusOne);
      bfsQueue.push(currentNode.plusOne);
      bfsQueue.push(currentNode.twoTimes);
    }
  }
}

void getShortInfos(int &shortestLevels, int &shortestCount) {
  cout << shortestLevels << '\n' << shortestCount;
}