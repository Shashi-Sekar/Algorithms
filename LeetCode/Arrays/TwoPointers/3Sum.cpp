#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        if (nums[0] > 0)
            return triplets;
            
        int n = nums.size();
        int target = 0;
        int start = 0;
        int end = n-1;

        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            
            target = 0 - nums[i];
            start = i+1;
            end = n-1;
            
            while (start < end) {
                int current = nums[start] + nums[end];
                if (current > target) {
                    end--;
                } else if (current < target) {
                    start++;
                } else {
                    int startNum = nums[start];
                    int endNum = nums[end];
                    triplets.push_back({nums[i], nums[start], nums[end]});

                    while (start < end && nums[start] == startNum) {
                        start++;
                    }
                    while (end > start && nums[end] == endNum) {
                        end--;
                    }
                }
            }
        }

        return triplets;
    }
};