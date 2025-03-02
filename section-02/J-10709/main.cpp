/*
 * Problem: 10709
 * URL: https://www.acmicpc.net/problem/10709
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char CLOUD = 'c';

void readSkyGrid(vector<vector<bool>> &skyGrid) {
  int rowCount = skyGrid.size(), colCount = skyGrid[0].size();

  for (int rowIndex = 1; rowIndex < rowCount; ++rowIndex) {
    string rowSky;
    getline(cin >> ws, rowSky);
    for (int colIndex = 1; colIndex < colCount; ++colIndex) {
      bool isCloud = (rowSky[colIndex - 1] == CLOUD);
      skyGrid[rowIndex][colIndex] = isCloud;
    }
  }
}

void printSky(vector<vector<bool>> &skyGrid) {
  int rowCount = skyGrid.size(), colCount = skyGrid[0].size();

  for (int rowIndex = 1; rowIndex < rowCount; ++rowIndex) {
    for (int colIndex = 1; colIndex < colCount; ++colIndex) {
      cout << skyGrid[rowIndex][colIndex] << ' ';
    }

    cout << '\n';
  }
}

void printCloudShowTime(vector<vector<int>> &cloudShowTime) {
  int rowCount = cloudShowTime.size(), colCount = cloudShowTime[0].size();

  for (int rowIndex = 1; rowIndex < rowCount; ++rowIndex) {
    for (int colIndex = 1; colIndex < colCount; ++colIndex) {
      cout << cloudShowTime[rowIndex][colIndex] << ' ';
    }

    cout << '\n';
  }
}

void moveCloud(vector<vector<bool>> &skyGrid,
               vector<vector<int>> &cloudShowTime) {
  int rowCount = skyGrid.size(), colCount = skyGrid[0].size();

  for (int timeCount = 0; timeCount < colCount - 1; ++timeCount) {
    for (int rowIndex = 1; rowIndex < rowCount; ++rowIndex) {
      for (int colIndex = 1; colIndex < colCount; ++colIndex) {

        bool isCloudPosition = (skyGrid[rowIndex][colIndex] == true);
        bool isClearSky = (cloudShowTime[rowIndex][colIndex] == -1);

        if (isClearSky && isCloudPosition) {
          cloudShowTime[rowIndex][colIndex] = timeCount;
        }
      }

      vector<bool> updateRow = skyGrid[rowIndex];
      updateRow.insert(updateRow.begin(), false);
      updateRow.pop_back();
      skyGrid[rowIndex] = updateRow;
    }
  }
}

int main() {
  int initRowCount = 0, initColCount = 0;
  cin >> initRowCount >> initColCount;

  vector<vector<bool>> skyGrid(initRowCount + 1,
                               vector<bool>(initColCount + 1, false));
  readSkyGrid(skyGrid);

  vector<vector<int>> cloudShowTime(initRowCount + 1,
                                    vector<int>(initColCount + 1, -1));
  moveCloud(skyGrid, cloudShowTime);
  printCloudShowTime(cloudShowTime);
  return 0;
}