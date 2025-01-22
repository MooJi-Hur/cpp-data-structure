#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nodeCount, edgeCount, startNode;

void buildAdjacencyList(vector<vector<int>> &adjacencyList);
void bfsTraversal(vector<vector<int>> &adjacencyList, vector<bool> &visited, vector<int> &resultBfs);
void printTraversal(vector<int> &resultBfs);

int main()
{
    cin >> nodeCount >> edgeCount;
    vector<vector<int>> edges(nodeCount, vector<int>(edgeCount));

    buildAdjacencyList(edges);

    cin >> startNode;
    vector<bool> visited(nodeCount, false);
    vector<int> resultBfs;

    bfsTraversal(edges, visited, resultBfs);

    printTraversal(resultBfs);

    return 0;
}

void buildAdjacencyList(vector<vector<int>> &adjacencyList)
{
    for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex)
    {
        int u, v;
        cin >> u >> v;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // bi-direction
    }
};

void bfsTraversal(vector<vector<int>> &adjacencyList, vector<bool> &visited, vector<int> &resultBfs)
{
    queue<int> bfsQueue; // 현재 레벨의 모든 노드 조회, 동일한 노드가 들어가지 못하게 막아야함

    visited[startNode] = true; // 시작점은 추후 조회하지 않으므로 미리 방문 처리
    bfsQueue.push(startNode);

    while (!bfsQueue.empty())
    {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();

        resultBfs.push_back(currentNode);

        for (int neighbor : adjacencyList[currentNode])
        {
            // 방문하지 않았던 노드만 큐에 추가
            if (!visited[neighbor])
            {
                visited[neighbor] = true; // 노드가 큐에 들어가기 전에 방문 처리
                bfsQueue.push(neighbor);
            }
        }
    }
}

void printTraversal(vector<int> &resultBfs)
{
    for (int charIndex : resultBfs)
    {
        int startA = 65;
        char nodeAlphbet = startA + charIndex;
        cout << nodeAlphbet << ' ';
    }
    cout << '\n';
};
