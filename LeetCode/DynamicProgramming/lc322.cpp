#include<iostream>
#include<vector>

using namespace std;

class Solution {
    const int maxAmount = 10001;

public:
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(), coins.end());
        
        vector<int> answer(amount+1, maxAmount);
        answer[0] = 0;
        int n = coins.size();

        for(int subAmount = 1; subAmount <= amount; subAmount++) {
            for(int i = 0; i < n; i++) {
                int remaining = subAmount - coins[i];
                if (remaining < 0) 
                    continue;
                answer[subAmount] = min(answer[subAmount], answer[remaining]+1);
            }
        }

        return answer[amount] == maxAmount ? -1 : answer[amount];
    }
};

int main() {
    return 0;
}