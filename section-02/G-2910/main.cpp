/*
 * Problem: 2910
 * URL: https://www.acmicpc.net/problem/2910
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct Order
{
    int keyCount = 0;
    int initialIndex = -1;
} Order;

void readMessages(int &messageCount, unordered_map<int, Order> &frequencyMap);

bool sortByFrequencyAndOrder(const pair<int, Order> &a, const pair<int, Order> &b);
void sortMessages(unordered_map<int, Order> &frequencyMap, vector<int> &sortedMessages);

void printFrequency(vector<int> &sortedMessages);

int main()
{
    int messageCount = 0, maxMessage = 0;
    cin >> messageCount >> maxMessage;

    unordered_map<int, Order> frequencyMap;
    readMessages(messageCount, frequencyMap);

    vector<int> sortedMessages;
    sortMessages(frequencyMap, sortedMessages);

    printFrequency(sortedMessages);

    return 0;
}

void readMessages(int &messageCount, unordered_map<int, Order> &frequencyMap)
{
    for (int messageIndex = 0; messageIndex < messageCount; ++messageIndex)
    {

        int messageKey = 0;
        cin >> messageKey;

        auto hasKey = frequencyMap.find(messageKey);

        if (hasKey != frequencyMap.end())
        {
            frequencyMap[messageKey].keyCount++;
        }
        else
        {
            frequencyMap[messageKey] = {1, messageIndex};
        }
    }
};

bool sortByFrequencyAndOrder(const pair<int, Order> &a, const pair<int, Order> &b)
{
    auto [keyA, orderA] = a;
    auto [keyB, orderB] = b;

    if (orderA.keyCount != orderB.keyCount)
    {
        return orderA.keyCount > orderB.keyCount;
    }

    return orderA.initialIndex < orderB.initialIndex;
};

void sortMessages(unordered_map<int, Order> &frequencyMap, vector<int> &sortedMessages)
{

    vector<pair<int, Order>> frequencyVector(frequencyMap.begin(), frequencyMap.end());

    sort(frequencyVector.begin(), frequencyVector.end(), sortByFrequencyAndOrder);

    for (auto &[messageKey, messageOrders] : frequencyVector)
    {
        for (int i = 0; i < messageOrders.keyCount; ++i)
        {
            sortedMessages.push_back(messageKey);
        }
    }
};

void printFrequency(vector<int> &sortedMessages)
{
    for (auto message : sortedMessages)
    {
        cout << message << ' ';
    }
};