/*
LC 227. Basic Calculator II
*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution{
    public:
    int calculate(string s) {
        int n = s.size();

        if(n <= 0)
            return 0;

        int num = 0;
        char prev_op = '+';
        int total_sum = 0;
        int top_element = 0;

        for(int i = 0; i < n; i++){
            char c = s[i];

            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }

            if(!isdigit(c) && !iswspace(c) || i == n-1){
                char curr_op = c;
                if(prev_op == '-'){
                    total_sum += top_element;
                    top_element = -num;
                }
                else if(prev_op == '+'){
                    total_sum += top_element;
                    top_element = num;
                }
                else if(prev_op == '*'){
                    top_element = top_element * num;
                }
                else{
                    top_element = top_element / num;
                }

                prev_op = curr_op;
                num = 0;
                
            }
        }

        total_sum += top_element;
        return total_sum;
    }

};

int main(){
    Solution s;
    return 0;
}