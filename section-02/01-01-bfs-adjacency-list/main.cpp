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
    queue<int> bfsQueue;

    visited[startNode] = true;
    bfsQueue.push(startNode);

    while (!bfsQueue.empty())
    {
        int currentNode = bfsQueue.front();

        resultBfs.push_back(currentNode);
        bfsQueue.pop();

        for (int neighbor : adjacencyList[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
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
