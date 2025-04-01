- getline 시 char 다루기
    ```c++
    constexpr char ROAD = '1';
    inGrid[rowIndex][colIndex] = (currentRow[colIndex] == ROAD);
    ```

- size()를 다룰 때 음수 유의
    ```c++
    bool isInBoundRow = nextRow >= 0 && nextRow < (int)inGrid.size();
    bool isInBoundCol = nextCol >= 0 && nextCol < (int)inGrid[0].size();
    ```

- 방문 조건을 다룰 때, 참거짓
```c++
bool canMove =
    isInBoundRow && isInBoundCol && (inGrid[nextRow][nextCol] == true);

bool canVisit = canMove && (visitCountGrid[nextRow][nextCol] == 0);
```