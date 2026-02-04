#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums, int divisions) {
        int n = nums.size();
        int start = 0;
        int k = 0;

        while (k < divisions) {
            if (k % 2 == 0) {
                while (start < n-1 && nums[start] < nums[start+1]) {
                    start++;
                }
            } else {
                while (start < n-1 && nums[start] > nums[start+1]) {
                    start++;
                }
            }

            k++;
            if ((k != divisions) && (start == 0 || start == n-1)) {
                return false;
            }
        }

        return start == n-1;
    }
};

int main() {
    return 0;
}