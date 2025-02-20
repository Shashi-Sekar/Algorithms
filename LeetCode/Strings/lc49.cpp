/*
LC 49. Group Anagrams

Ideas:

Algorithm


Time Complexity:
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> root;
        vector<vector<string>> grouped;

        for(int i = 0; i < n; i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            root[word].push_back(strs[i]);
        }

        for(auto& it: root){
            grouped.push_back(it.second);
        }

        return grouped;
    }
};

int main(){
    Solution s;

    return 0;
}