/*
LC 42. Trapping rainwater
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_volume = 0;

        vector<int> leftHeight(n , 0);
        vector<int> rightHeight(n, 0);

        leftHeight[0] = height[0];
        for(int i = 1; i < n; i++){
            leftHeight[i] = max(leftHeight[i-1], height[i]);
        }

        rightHeight[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightHeight[i] = max(rightHeight[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            int minHeight = min(leftHeight[i], rightHeight[i]);
            total_volume += minHeight - height[i];
        }

        return total_volume;   
    }
};

int main(){
    Solution s;
    return 0;
}