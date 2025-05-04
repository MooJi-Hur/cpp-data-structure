/*
 * Problem: 17136
 * URL: https://www.acmicpc.net/problem/17136
 */

#include <array>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

constexpr int SIDE_SIZE = 10;
constexpr int PAPER_PLACE = 1;
constexpr int IMPOSSIBLE_RESULT = -1;

constexpr int MAX_PAPER_COUNT = 5;
constexpr int PAPER_TYPE_COUNT = 5;

array<int, PAPER_TYPE_COUNT + 1> paperCounts;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void readGrid(int &sumPapers, vector<vector<bool>> &inGrid) {
  for (size_t rowIndex = 0; rowIndex < inGrid.size(); ++rowIndex) {
    for (size_t colIndex = 0; colIndex < inGrid[0].size(); ++colIndex) {
      int cell;
      cin >> cell;
      bool needPaper = (cell == PAPER_PLACE);

      if (needPaper) {
        sumPapers++;
      }

      inGrid[rowIndex][colIndex] = needPaper;
    }
  }
};

void initPapers() {
  paperCounts.fill(MAX_PAPER_COUNT);
  paperCounts[0] = 0;
};

void dfs(int &sumPapers, pair<int, int> currentPoint) {
  auto [currentRow, currentCol] = currentPoint;

  for (auto [deltaRow, deltaCol] : DELTAS) {
    int nextRow = currentRow + deltaRow;
    int nextCol = currentCol + deltaCol;
  }
};

void usePapers(int &sumPapers,
               vector<vector<bool>> &inGrid,
               vector<vector<bool>> &visited) {

  if (sumPapers == 0) {
    return;
  }

  for (int typeIndex = PAPER_TYPE_COUNT; typeIndex > 0; --typeIndex) {
    while (paperCounts[typeIndex] > 0) {
      pair<int, int> startPoint = {0, 0};
      dfs(sumPapers, startPoint);
      paperCounts[typeIndex]--;
    }

    cout << paperCounts[typeIndex] << ' ';
  }
};

int main() {

  //  입력
  //  총 10개의 줄에 종이의 각 칸에 적힌 수가 주어진다.
  int sumPapers = 0;
  vector<vector<bool>> inGrid(SIDE_SIZE, vector<bool>(SIDE_SIZE, false));
  readGrid(sumPapers, inGrid);

  //   <그림 1>과 같이 정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의
  //   크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며,
  // 각 종류의 색종이는 5개씩 가지고 있다.
  initPapers();

  // 색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로
  // 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다.
  // 색종이를 붙일 때는 종이의 경계 밖으로 나가서는
  // 안되고, 겹쳐도 안 된다. 또, 칸의 경계와 일치하게 붙여야 한다.
  vector<vector<bool>> visited(SIDE_SIZE, vector<bool>(SIDE_SIZE, false));
  usePapers(sumPapers, inGrid, visited);

  // 1이 적힌 칸은 모두 색종이로 덮여져야 한다.
  // 0이 적힌 칸에는 색종이가 있으면 안 된다.

  // 종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를
  // 구해보자.

  int minPaperCount = INT_MAX;

  //  출력
  //  모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 1을 모두 덮는 것이
  //  불가능한 경우에는 -1을 출력한다.
  if (minPaperCount == INT_MAX) {
    cout << IMPOSSIBLE_RESULT;
  } else {
    cout << minPaperCount;
  }
  return 0;
}
