#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int dijkstra(int n, vector<vector<pair<int,int>>>& adjacencyList) {
        vector<int> costs(n, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto [currentCost, currentNode] = pq.top();
            pq.pop();

            if (costs[currentNode] != -1 && costs[currentNode] < currentCost) {
                continue;
            }

            for (auto& [targetCost, targetNode]: adjacencyList[currentNode]) {
                int newCost = currentCost + targetCost;

                if (costs[targetNode] == -1 || costs[targetNode] > newCost) {
                    costs[targetNode] = newCost;
                    pq.push({newCost, targetNode});
                }
            }
        }

        return costs[n-1];
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjacencyList(n);
        
        int numEdges = edges.size();
        for (int i = 0; i < numEdges; i++) {
            adjacencyList[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            adjacencyList[edges[i][1]].push_back({2*edges[i][2], edges[i][0]});
        }

        return dijkstra(n, adjacencyList);
    }
};