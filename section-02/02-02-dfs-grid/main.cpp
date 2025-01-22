#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

constexpr bool IS_ACCESSABLE = true;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int rowCount, colCount;
int startRow, startCol;

void readGrid(vector<vector<bool>> &grid);

bool validNext(int rowIndex, int colIndex, vector<vector<bool>> &grid, vector<vector<bool>> &visited);
void dfsTraversal(vector<vector<bool>> &grid, vector<vector<bool>> &visited);

void printVisited(vector<vector<bool>> &visited);

int main()
{
    cin >> rowCount >> colCount;

    vector<vector<bool>> grid(rowCount, vector<bool>(colCount, false));
    readGrid(grid);

    cin >> startRow >> startCol;

    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    dfsTraversal(grid, visited);

    printVisited(visited);

    return 0;
}

void readGrid(vector<vector<bool>> &grid)
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
    bool isInbounds = isAboveMin && isBelowMax;

    bool isSafeNext = isInbounds && (grid[rowIndex][colIndex] == IS_ACCESSABLE);

    bool canMoveNext = isSafeNext && !visited[rowIndex][colIndex];

    return canMoveNext;
};

void dfsTraversal(vector<vector<bool>> &grid, vector<vector<bool>> &visited)
{
    stack<pair<int, int>> dfsStack;

    dfsStack.push({startRow, startCol});

    while (!dfsStack.empty())
    {
        auto &[currentRow, currentCol] = dfsStack.top();
        dfsStack.pop();

        if (visited[currentRow][currentCol] == true)
            continue;

        visited[currentRow][currentCol] = true;

        for (auto &[deltaRow, deltaCol] : DELTAS)
        {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool isValidNext = validNext(nextRow, nextCol, grid, visited);

            if (isValidNext)
            {
                dfsStack.push({nextRow, nextCol});
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