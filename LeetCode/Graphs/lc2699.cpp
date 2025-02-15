/*

Idea:
    If the shortest path from the source to the destination without any modification is less than the target, then no matter what modifications we do, we cannot achieve the target.
    If the shortest path from the source to the destination without any modification is equal to the target, then we have already achieved the target. So, we modify the edge to have the maximum weight (we do not want a new shortest path).
    If the shortest path from the source to the destination with the least modification is greater than the target, then target cannot be achieved.
    Add the negative edge one by one by setting the weight to 1 and check if the target can be achieved.
    If target cannot be achieved, then there are still negative edges that we need to consider
    If target can be achieved, then we need to add the remaining weight to the edge to achieve the target.

Algorithms used:
    Dijkstra Algorithm

Algorithm:
    check if the shortest path from the source to the destination without any modification is less than the target
        if yes, then return empty vector
    check if the shortest path from the source to the destination without any modification is equal to the target
        match = true
    We iterate over the edges:
        if the edge can be modified
        if match is true
            set the weight to the maximum value (we do not want a new shortest path)
        else
            set the weight to 1 
        Add the edge to the graph
        compute the new shortest path from the source to the destination
        if the shortest path is less than or equal to the target, then we have achieved the target
            add the remaining weight (target - shortest path) to the edge
            match = true
*/


#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

const int mod = 2 * 1e9;

class Solution {
    int dijkstra(vector<vector<pair<int, int>>>& graph, int source, int destination){
        /*
        Dijsktra algorithm to find the shortest path from the source to the destination
        Implemented using min heap (priority queue)
        Parameters:
            graph: The adjacency list representation of the graph (vector of vector of pairs)
            source: source node (int)
            destination: destination node (int)
            target: target value (int)
        Returns:
            The shortest distance from the source to the destination
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, source);

        vector<int> distance(graph.size(), INT_MAX);
        distance[source] = 0;

        while(!pq.empty()){
            auto [current_distance, node] = pq.top();
            pq.pop();

            for(auto& [neighbor, dist]: graph[node]){
                if(current_distance + dist < distance[neighbor]){
                    distance[neighbor] = current_distance + dist;
                    pq.emplace(distance[neighbor], neighbor);
                }
            }
            
        }

        return distance[destination];
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector< vector<pair<int, int>> > graph(n);
        
        //Store the edges in the form of adjacency list
        for(int i = 0; i < edges.size(); i++){

            //Do not include the edges, that needs to be modified
            if(edges[i][2] != -1){
                graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
                graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            }
        }

        //Compute the shortest path from the source to the destination without any edges to be modified
        int shortest_without_modification = dijkstra(graph, source, destination);
        
        //If this shortest distance is less than the target, then no matter any modification we do, we cannot go below the target (modifications are positive)
        //Return empty vector
        if(shortest_without_modification < target){
            return {};
        }

        //A variable to keep track of whether the shortest path is achieved
        bool match = false;

        //If the shortest path without any modification is equal to the target, then we have already achieved the target
        if(shortest_without_modification == target){
            match= true;
        }

        //Iterate over the edges that needs to be modified
        for(int i = 0; i < edges.size(); i++){

            //If the edge cannot be modified, then skip
            if(edges[i][2] != -1){
                continue;
            }

            //If the shortest path is already achieved, then set the weight to be the maximum value (we do not want a new shortest path)
            if(match){
                edges[i][2] = mod;
            }
            //Else set the weight to be 1 (minimum modification)
            else{
                edges[i][2] = 1;
            }

            //Add the edge to the graph
            graph[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            graph[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);

            //If the shortest path is not achieved, then check if the shortest path can be achieved by modifying this edge
            if(!match){
                int shortest_with_modification = dijkstra(graph, source, destination);
                //If this is the only missing edge between the source and destination, then we need to add the remaining weight (target - shortest_with_modification) to this edge to achieve the target
                if(shortest_with_modification <= target){
                    match = true;   
                    edges[i][2] += target - shortest_with_modification;
                }
            }
        }

        //If the target is not achieved, then return empty vector
        if(!match){
            return {};
        }
        
        return edges;
    }
};