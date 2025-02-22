/*
LC 207. Course Schedule

Ideas: 

Algorithm: 

Time Complexity: 
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    bool cycle(vector<vector<int>>& graphs, vector<int>& visited, int start_node){
        /*
        Returns true if there is a cycle in the graph
        */
        if(visited[start_node] == 1)
            return true;

        if(visited[start_node] == 2)
            return false;
            
        visited[start_node] = 1;

        for(auto neighbor: graphs[start_node]){
            if(cycle(graphs, visited, neighbor))
                return true;
        }

        visited[start_node] = 2;
        return false;
    }

    public:

        bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
            vector<vector<int>> graph(numCourses);
            vector<int> inDegree(numCourses, 0);

            for(auto& prereq: prerequisites){
                graph[prereq[1]].push_back(prereq[0]);
                inDegree[prereq[0]]++;
            }

            //Depth First Search to detect cycle
            vector<int> visited(numCourses, 0);
            //Visited can take 3 values:
            //0: Not visited
            //1: Visited in the current dfs
            //2: Visited in earlier dfs

            for(int i = 0; i < numCourses; i++){
                if(visited[i] == 0 && cycle(graph, visited, i)){
                    return false;
                }
            }
            
            //Breadth First Search to detect cycle
            
            return true;
        }
};

int main(){
    Solution s;

    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1,0}, {0,2}, {1,2}};

    bool canFinish = s.canFinish(numCourses, prerequisites);
    if(!canFinish)
        cout<<"A student cannot complete all the courses given the prerequisite conditions"<<endl;
    else
        cout<<"A student can complete all the courses given the prerquisite conditions"<<endl;

    return 0;
}
