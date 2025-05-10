/*
 * Problem: 17471
 * URL: https://www.acmicpc.net/problem/17471
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

constexpr int NO_GROUP = -1;
constexpr int MAX_DIFFERENCE = 100 * 10 + 1;

void readCity(const int regionCount,
              vector<int> &populations,
              map<int, vector<int>> &allNeighbors) {

  for (int regionIndex = 1; regionIndex <= regionCount; ++regionIndex) {
    cin >> populations[regionIndex];
  }

  for (int regionIndex = 1; regionIndex <= regionCount; ++regionIndex) {
    int neighborCount = 0;
    cin >> neighborCount;
    vector<int> neighbors(neighborCount);
    for (int neighborIndex = 0; neighborIndex < neighborCount;
         ++neighborIndex) {
      cin >> neighbors[neighborIndex];
    }

    allNeighbors[regionIndex] = neighbors;
  }
}

void searchRegionPath(const int startIndex,
                      vector<bool> &visited,
                      map<int, vector<int>> &allNeighbors) {
  queue<int> bfsQueue;
  bfsQueue.push(startIndex);
  visited[startIndex] = true;

  while (!bfsQueue.empty()) {

    int currentRegion = bfsQueue.front();
    bfsQueue.pop();

    for (size_t neighborIndex = 0;
         neighborIndex < allNeighbors[currentRegion].size(); ++neighborIndex) {
      int nextRegion = allNeighbors[currentRegion][neighborIndex];
      if (!visited[nextRegion]) {
        visited[nextRegion] = true;
        bfsQueue.push(nextRegion);
      }
    }
  }
}

void getDifference(vector<int> &populations,
                   int &minDifference,
                   vector<int> &firstGroup,
                   vector<int> &secondGroup) {

  int firstGroupPopulation = 0;
  int secondGroupPopulation = 0;

  for (const int region : firstGroup) {
    firstGroupPopulation += populations[region];
  }

  for (const int region : secondGroup) {
    secondGroupPopulation += populations[region];
  }

  int currentDifference = abs(firstGroupPopulation - secondGroupPopulation);

  if (currentDifference < minDifference) {
    minDifference = currentDifference;
  }
}

void validateNeighbors(vector<int> &group,
                       map<int, vector<int>> &neighbors,
                       map<int, vector<int>> allNeighbors) {

  for (auto &[region, initNeighbors] : allNeighbors) {
    for (int regionName : group) {

      if (find(initNeighbors.begin(), initNeighbors.end(), regionName) !=
          initNeighbors.end()) {

        neighbors[region].push_back(regionName);
      }
    }
  }
}

void validateEachGroup(const int regionCount,
                       int &minDifference,
                       map<int, vector<int>> &allNeighbors,
                       vector<int> &populations) {
  int groupCount = 1 << regionCount;
  int uniqueGroupCount = groupCount >> 1;

  bool isMinDifference = false;
  for (int groupIndex = 0; groupIndex < uniqueGroupCount; ++groupIndex) {
    vector<int> firstGroup;
    vector<int> secondGroup;

    for (int regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
      int regionName = regionIndex + 1;
      bool groupName = groupIndex & (1 << regionIndex);
      groupName ? firstGroup.push_back(regionName)
                : secondGroup.push_back(regionName);
    }

    if (firstGroup.empty() || secondGroup.empty()) {
      continue;
    }

    vector<bool> firstGroupVisited(regionCount + 1, false);
    vector<bool> secondGroupVisited(regionCount + 1, false);

    map<int, vector<int>> firstNeighbors;
    map<int, vector<int>> secondNeighbors;

    validateNeighbors(firstGroup, firstNeighbors, allNeighbors);
    validateNeighbors(secondGroup, secondNeighbors, allNeighbors);

    int subFirstGroupCount = 0, subSecondGroupCount = 0;
    for (size_t regionIndex = 0; regionIndex < firstGroup.size();
         ++regionIndex) {
      int regionName = firstGroup[regionIndex];
      if (!firstGroupVisited[regionName]) {
        subFirstGroupCount++;
        searchRegionPath(regionName, firstGroupVisited, firstNeighbors);
      }
    }
    for (size_t regionIndex = 0; regionIndex < secondGroup.size();
         ++regionIndex) {
      int regionName = secondGroup[regionIndex];
      if (!secondGroupVisited[regionName]) {
        subSecondGroupCount++;
        searchRegionPath(regionName, secondGroupVisited, secondNeighbors);
      }
    }

    bool isLocalMinDifference =
        subFirstGroupCount == 1 && subSecondGroupCount == 1;

    if (isLocalMinDifference) {
      isMinDifference = true;
      getDifference(populations, minDifference, firstGroup, secondGroup);
    }
  }

  if (!isMinDifference) {
    minDifference = NO_GROUP;
  }
}

int main() {

  int regionCount = 0;
  cin >> regionCount;

  vector<int> populations(regionCount + 1);
  map<int, vector<int>> allNeighbors;
  readCity(regionCount, populations, allNeighbors);

  int minDifference = MAX_DIFFERENCE;
  validateEachGroup(regionCount, minDifference, allNeighbors, populations);

  if (minDifference == MAX_DIFFERENCE) {
    minDifference = NO_GROUP;
  }

  cout << minDifference;
  return 0;
}