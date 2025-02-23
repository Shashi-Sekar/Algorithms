/*
LC 79. Word Search
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    bool inBounds(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index){
        if(index == word.size())
            return true;
        
        if(!inBounds(row, col, board.size(), board[0].size()))
            return false;
        
        if(board[row][col] != word[index])
            return false;

        char original = board[row][col];
        board[row][col] = '.';
        
        bool exist = dfs(board, word, row+1, col, index+1) ||
                    dfs(board, word, row-1, col, index+1) ||
                    dfs(board, word, row, col-1, index+1) ||
                    dfs(board, word, row, col+1, index+1);
        
        board[row][col] = original;
        return exist;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    return 0;
}