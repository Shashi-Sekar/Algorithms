/*
LC 238. Product of Array Except Self

Ideas:

Algorithm:

Time Complexity:

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int product = 1;

        for(int i : nums){
            if(i != 0){
                product *= i;
            }
            else{
                zero++;
            }
        }

        if(zero > 1){
            return vector<int>(n, 0);
        }

        vector<int> answer;
        for(int i: nums){
            if(zero){
                if(i == 0)
                    answer.push_back(product);
                else
                    answer.push_back(0);
            }
            else{
                answer.push_back(product / i);
            }
        }

        return answer;
    }
};

int main(){
    Solution s;

    return 0;
}   