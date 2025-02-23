/*
LC 560. Subarray Sum Equals K

Ideas:
    1. Brute Force - For each index in the input array, find the cumulative sum from that index through the end of the array. If the cumulative sum equals k, increment the count
    2. First level Optimization
        2.1 Cumulative sum is prefix sum.
        2.2 Compute the prefix sum of the input array
        2.3 For each index i, check the number of 'j's such that prefix[i] - prefix[j] = k and j < i
        2.4 Still quadratic time complexity
    3. Second level Optimization
        3.1 Use a hash map to store the prefix sum for all j < i.
        3.2 This is used as a constant time lookup table to find the number of 'j's such that prefix[j] = prefix[j] - k
        3.3 Linear time Complexity and space complexity
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();

            int num_sub = 0;
            vector<int> prefix(n, 0);
            unordered_map<int, int> sums;
            
            //Handline the first element
            prefix[0] = nums[0];
            sums[prefix[0]] = 1;

            if(prefix[0] == k)
                num_sub = 1;

            //For elements from 1 through n-1
            for(int i = 1; i < n; i++){

                //Compute the prefix sum
                prefix[i] = prefix[i-1] + nums[i];

                //Add the number of subarrays with prefix sum = prefix[i] - k
                num_sub += sums[prefix[i]-k];

                //Increment the count of prefix[i]
                sums[prefix[i]]++;

                //Increment the count of subarrays if prefix[i] = k
                if(prefix[i] == k)
                    num_sub += 1;
                
            }

            return num_sub;

        }
};

int main(){
    return 0;
}