#include<iostream>
#include<vector>

using namespace std;

class Solution {
    
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> sub(n, vector<int>(n, 1));
        vector<int> sub(n, 1);
        int answer = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    sub[i] = max(sub[i], sub[j] + 1);
                }
            }
            answer = max(answer, sub[i]);
        }
        return answer;
    }
};

int main() {
    return 0;
}