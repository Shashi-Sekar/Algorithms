#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {

private:
    vector<long long> dijkstra(int start, vector<vector<pair<int, int>>>& adjacencyList) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, start});
        vector<long long> minCost(26, -1);

        while(!pq.empty()) {
            auto [currentCost, currentChar] = pq.top();
            pq.pop();

            if (minCost[currentChar] != -1 && minCost[currentChar] < currentCost)
                continue;


            for (auto& [targetChar, cost]: adjacencyList[currentChar]) {
                long long newCost = cost + currentCost;

                if (minCost[targetChar] == -1 || minCost[targetChar] > newCost) {
                    minCost[targetChar] = newCost;
                    pq.push({newCost, targetChar});
                }
            }
        }

        return minCost;

    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adjacencyList(26);

        int n = original.size();

        for(int i = 0; i < n; i++) {
            adjacencyList[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        vector<vector<long long>> minCosts(26, vector<long long> (26));

        for(int i = 0; i < 26; i++) {
            minCosts[i] = dijkstra(i, adjacencyList);
        }


        long long total = 0;
        int m = source.length();

        for(int i = 0; i < m; i++){
            if (source[i] != target[i]) {
                long long cost = minCosts[source[i] - 'a'][target[i] - 'a'];
                if(cost == -1)
                    return -1;
                total += cost;
            }
        }

        return total;
    }
};