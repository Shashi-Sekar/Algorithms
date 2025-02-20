/*
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    struct Comparator{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        }
    };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){if(a[0] != b[0]) return a[0] < b[0]; else return a[1] < b[1]; });
        
        int current_start = intervals[0][0];
        int current_end = intervals[0][1];

        for(int i = 1; i < n; i++){
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];

            if(next_start <= current_end){
                current_end = max(next_end, current_end);
            }
            else{
                merged.push_back({current_start, current_end});
                current_start = next_start;
                current_end = next_end;
            }
        }

        merged.push_back({current_start, current_end});
        return merged;
    }
};

int main(){
    Solution s;
    return 0;
} 