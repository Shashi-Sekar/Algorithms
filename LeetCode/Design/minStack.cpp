/*
LC 155. Min Stack

We need the getMinimum() to be of O(1) time complexity. 
We can achieve this by keeping track of the minimum element at each level of the stack.

*/

#include<iostream>
#include<deque>

using namespace std;

class MinStack{
    deque<int> stack;
    deque<int> minValues;

    public:
        MinStack(){
            stack = deque<int>();
            minValues = deque<int>();
        }

        void push(int val){
            stack.push_back(val);
            int minVal = minValues.empty() ? val : min(val, minValues.back());
            minValues.push_back(minVal);
        }

        void pop(){
            stack.pop_back();
            minValues.pop_back();
        }

        int getTop(){
            return stack.back();
        }

        int getMinimum(){
            return minValues.back();
        }
};

int main(){
    
    return 0;
}
