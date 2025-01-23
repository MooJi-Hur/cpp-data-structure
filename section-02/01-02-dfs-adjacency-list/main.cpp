#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int nodeCount, edgeCount, startNode;

void buildAdjacencyList(vector<vector<int>> &adjacencyList);
void dfsTraversal(vector<vector<int>> &adjacencyList, vector<bool> &visited, vector<int> &resultDfs);
void printTraversal(vector<int> &resultDfs);

int main()
{
    cin >> nodeCount >> edgeCount;
    vector<vector<int>> edges(nodeCount, vector<int>(edgeCount));

    buildAdjacencyList(edges);

    cin >> startNode;

    vector<bool> visited(nodeCount, false);
    vector<int> resultDfs;

    dfsTraversal(edges, visited, resultDfs);

    printTraversal(resultDfs);

    return 0;
}

void buildAdjacencyList(vector<vector<int>> &adjacencyList)
{
    for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex)
    {
        int u, v;
        cin >> u >> v;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
};

void dfsTraversal(vector<vector<int>> &adjacencyList, vector<bool> &visited, vector<int> &resultDfs)
{
    stack<int> dfsStack; // 깊이 방향으로 조회하므로 동일한 노드가 여러 번 삽일될 수 있음

    dfsStack.push(startNode);

    while (!dfsStack.empty())
    {
        int currentNode = dfsStack.top();
        dfsStack.pop();

        if (visited[currentNode])
            continue; // 이미 방문한 노드는 방문 처리를 다시 하지 않음

        visited[currentNode] = true; // 스택에서 꺼낸 뒤, 방문 처리
        resultDfs.push_back(currentNode);

        for (int neighbor : adjacencyList[currentNode])
        {
            if (!visited[neighbor])
            {
                dfsStack.push(neighbor);
            }
        }
    }
};

void printTraversal(vector<int> &resultDfs)
{
    for (int nodeIndex : resultDfs)
    {
        int startAscii = 65;
        char nodeName = startAscii + nodeIndex;

        cout << nodeName << ' ';
    }

    cout << '\n';
};
