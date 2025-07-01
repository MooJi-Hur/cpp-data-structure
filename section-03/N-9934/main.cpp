/*
 * Problem: 9934
 * URL: https://www.acmicpc.net/problem/9934
 */

#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

// in
int depth = 0;

// logic
list<int> visitedOrder;

// out
map<int, vector<int>> orderByLevel;

void readVisited() {
  int visitedSize = (1 << depth) - 1;

  for (int visitedIndex = 0; visitedIndex < visitedSize; ++visitedIndex) {
    int visitedCell = 0;
    cin >> visitedCell;
    visitedOrder.push_back(visitedCell);
  }
}

void sortByLevel() {

  for (int levelIndex = depth; levelIndex > 0; --levelIndex) {

    vector<int> currentLevelNode;

    bool isOdd = true;
    for (auto visitedItor = visitedOrder.begin();
         visitedItor != visitedOrder.end();) {

      if (isOdd) {
        currentLevelNode.push_back(*visitedItor);
        visitedItor = visitedOrder.erase(visitedItor);
      } else {
        visitedItor++;
      }

      isOdd = !isOdd;
    }
    orderByLevel[levelIndex] = currentLevelNode;
  }
}

int main() {

  cin >> depth;

  readVisited();

  sortByLevel();

  for (auto [key, value] : orderByLevel) {
    for (auto cell : value) {
      cout << cell << ' ';
    }
    cout << '\n';
  }

  return 0;
}