#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

constexpr bool IS_ACCESSABLE = true;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int rowCount, colCount;
int startRow, startCol;

void buildGrid(vector<vector<bool>> &grid);

bool validNext(int rowIndex, int colIndex, vector<vector<bool>> &grid, vector<vector<bool>> &visited);
void bfsTraversal(vector<vector<bool>> &grid, vector<vector<bool>> &visited, vector<vector<int>> &distance);

void printVisited(vector<vector<bool>> &visited);
void printDistance(vector<vector<int>> &distance);

int main()
{
    cin >> rowCount >> colCount;

    vector<vector<bool>> grid(rowCount, vector<bool>(colCount, false));

    buildGrid(grid);

    cin >> startRow >> startCol;

    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    vector<vector<int>> distance(rowCount, vector<int>(colCount, 0));

    if (grid[startRow][startCol] == IS_ACCESSABLE)
    {
        bfsTraversal(grid, visited, distance);

        printVisited(visited);
        printDistance(distance);
    }

    return 0;
}

void buildGrid(vector<vector<bool>> &grid)
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < colCount; ++colIndex)
        {
            bool accessable = false;
            cin >> accessable;

            grid[rowIndex][colIndex] = accessable;
        }
    }
};

bool validNext(int rowIndex, int colIndex, vector<vector<bool>> &grid, vector<vector<bool>> &visited)
{
    bool isAboveMin = (rowIndex >= 0 && colIndex >= 0);
    bool isBelowMax = (rowIndex < rowCount && colIndex < colCount);
    bool isInBound = isAboveMin && isBelowMax;

    bool isSafeNext = isInBound && grid[rowIndex][colIndex] == IS_ACCESSABLE;
    bool canMoveNext = isSafeNext && !visited[rowIndex][colIndex];

    return canMoveNext;
};

void bfsTraversal(vector<vector<bool>> &grid, vector<vector<bool>> &visited, vector<vector<int>> &distance)
{
    queue<pair<int, int>> bfsQueue;

    bfsQueue.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!bfsQueue.empty())
    {
        auto [currentRow, currentCol] = bfsQueue.front();
        bfsQueue.pop();

        for (auto &[deltaRow, deltaCol] : DELTAS)
        {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool isValidNext = validNext(nextRow, nextCol, grid, visited);

            if (isValidNext)
            {
                visited[nextRow][nextCol] = true;
                distance[nextRow][nextCol] = distance[currentRow][currentCol] + 1;
                bfsQueue.push({nextRow, nextCol});
            }
        }
    }
};

void printVisited(vector<vector<bool>> &visited)
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < colCount; ++colIndex)
        {
            cout << visited[rowIndex][colIndex] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
};

void printDistance(vector<vector<int>> &distance)
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < colCount; ++colIndex)
        {
            cout << distance[rowIndex][colIndex] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
};
