/*
LC 416. Partition Equal Subset Sum

Ideas:
    1. Not greedy because 
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    bool recursion(vector<int>& nums, int index, int target, vector<vector<int>>& subset){
        if(target == 0)
            return true;

        if(index >= nums.size() || target < 0)
            return false;
        
        if(subset[index][target] != -1)
            return subset[index][target];

        subset[index][target] = recursion(nums, index+1, target-nums[index], subset) || recursion(nums, index+1, target, subset);
    
        return subset[index][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i = 0; i < n; i++)
            totalSum += nums[i];
        
        if(totalSum % 2)
            return false;

        int target = totalSum / 2;
        //vector<vector<bool>> subset(n+1, vector<bool>(target+1, false));
        vector<bool> prev(target+1, false);
        vector<bool> curr(target+1, false);

        prev[0] = true;
        curr[0] = true;
        
        for(int i = n-1; i >= 0; i--){
            for(int k = 1; k <= target; k++){
                bool notTake = prev[k];
                bool take = false;
                if(nums[i] <= k)
                    take = prev[k-nums[i]];
                curr[k] = take || notTake;
            }
            prev = curr;
        }
        /*
        for(int i = 1; i < n; i++){
            for(int k = 1; k <= target; k++){
                bool notTake = subset[i-1][k];
                bool take = false;
                if(nums[i] <= k)
                    take = subset[i-1][k-nums[i]];

                subset[i][k] = take || notTake;
            }
        }
        */

        return prev[target];
    }
};

int main(){
    Solution s;
    return 0;
}