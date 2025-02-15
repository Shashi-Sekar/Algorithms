/*

Constraints:
        1 <= n <= 1000

Ideas:
    Need to check every number from 1 to n
    Compute the square of the number
    Check if the string version of the square can be partitioned such that the sum of the partitions is equal to the number
    Find the sum of all such numbers

    Hardcoding the punishment numbers for n = 1 to 1000 is not going to work because the method find such numbers is the solution to this problem

    Where to optimize?
        Checking part can be optimized
        Brute force approach would be to check all the partitions of the string. Time complexity is O(2^n) where n is the number of digits in the squared number
        Instead of checking all possible partitions, we can check only the valid partitions and cut short the remaining
        This can be done using recursive backtracking

        Bactracking:
        At each position in the string, we can consider a substring of any length from that position and add it to the running sum.
        If at any point the running sum exceeds the number, we stop exploring that
        
        This can be further optimized by storing the results - memoization

        What are the dimensions that we need to consider?
            The index of the number string - equal to the number of digits in the squared number
            The running sum - Maximum is the number itself, since we cut short the exploration when the sum exceeds the number

        2-dimensional memoization array
        memo[start_index][sum] represents whether
                                        a partition starting from the <start_index>, 
                                        with a current running sum of <sum> 
                                        can lead to a sum equal to the number

Algorithm

recursive (int start_index, int sum, int target, string num_str, memo[][])
    if start_index >= len(num_str)
        return false
    
    if sum > target
        return false
    
    if memo[start_index][sum] != -1
        return memo[start_index][sum]

    partition <- false

    for i from start_index to len(num_str)
        substr <- substring starting from i, size: i - start_index + 1
        num_int <- convert substr to int

        new_sum <- sum + num_int
        partition <- paritition || recursive(i + 1, new_sum, target, num_str, memo)
        
        if partition
            return true

    return memo[start_index][sum] = partition

punishmentNumber(int n)
    
    for num from 1 to n
        square <- num * num
        num_str <- convert square to string
        memo <- 2D array of size len(num_str) * num, initialized to -1
        if recursive(0, 0, num, num_str, memo)
            sum += num

    return sum

Time Complexity:
    time complexity for recurion 
        Number of recursion calls = (log(n)^2) base 10 = (log n) base 10
        At each call, we check if we can partition or not. 
        Therefore the time complexity is O(2^(log(n) base 10))

    We do this for n numbers, so the overall time complexity is O(n * 2^(log(n) base 10))

Space Complexity:
    recursive call stack - O(log(n) base 10)
    memoization array - O(n * log(n) base 10)
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
    bool recursive(int start_index, int sum, int target, string num_str, vector<vector<int>>& memo){
        if(start_index >= num_str.size())
            return sum == target;
        
        if(sum > target)
            return false;
        
        if(memo[start_index][sum] != -1)
            return memo[start_index][sum];
        
        bool partition = false;

        for(int current_index = start_index; current_index < num_str.size(); current_index++){
            string substr = num_str.substr(start_index, current_index - start_index + 1);
            int num_int = stoi(substr);

            int new_sum = sum + num_int;
            partition = partition || recursive(current_index + 1, new_sum, target, num_str, memo);

            if(partition)
                return true;
        }

        return memo[start_index][sum] = partition;
    }
    public:
        int punishmentNumber(int n){
            int sum = 0;

            for(int num = 1; num <= n; num++){
                int square = num * num;

                string num_str = to_string(square);
                vector<vector<int>> memo(num_str.size(), vector<int>(num+1, -1));

                if(recursive(0, 0, num, num_str, memo))
                    sum += square;
            }

            return sum;
        }
};

int main(){
    Solution sol;
    int n;

    cout << "Enter the value of n (from 1 to 1000): ";
    cin >> n;

    cout << "The sum of all punishment numbers from 1 to " << n << " is: " << sol.punishmentNumber(n) << endl;

    return 0;
}