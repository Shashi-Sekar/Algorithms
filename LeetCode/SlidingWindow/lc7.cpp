/*

7. Longest Substring Without Repeating Characters

Ideas: 
    Brute Force: Start from each character, find the longest subtring that can be formed without repeating characters; Use a set to keep track of unique characters
    
    Sliding Window:
        Add the character to the queue
        If the character is repeated, remove the characters from the queue until the character is removed
        The maximum length is the size of the queue at any step
        Use a set to keep track of unique characters
    
    Optimized Sliding Window:
        No need for a queue. Use a pointer to the start of the substring.
        If the character is repeated, increment the start_index until after the repeated character
        Use a set to keep track of unique characters
    
    Further Optimization:
        Use a vector to keep track of the last appearance of each character
        Use a variable (start_index) to store the start of the substring
        The last appearance of each character in the substring is updated as the character is encountered
        If a character in the substring is encountered again, update the start_index to the last appearance of the character + 1

Time Complexity: O(n)
Space Complexity: O(1)

Algorithm:
    Initialize a vector to store the last appearance of each character
    Initialize a variable to store the start of the substring
    Initialize a variable to store the maximum length of the substring
    Iterate through the string
        If the last appearance of the character is greater than equal to the start of the substring
            Update the start of the substring to the last appearance of the character + 1
        Update the last appearance of the character
        Update the maximum length of the substring
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstring(string s) {

        //NOTE: The string can contain any ASCII characters. So, the size of the vector is 256
        vector<int> lastAppearance(256, -1);
        int left = 0;

        int n = s.size();
        int max_length = 0;

        for(int right = 0; right < n; right++){
            if(lastAppearance[s[right]] >= left){
                left = lastAppearance[s[right]] + 1;
            }

            lastAppearance[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

int main(){
    Solution s;

    return 0;
}