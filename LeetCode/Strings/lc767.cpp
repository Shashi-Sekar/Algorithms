/*
767. Reorganize String

Ideas:
    Compute the frequency of each character in the string
    Sort them based on the frequency
    If the most frequent character has a frequency greater than half the length of the string, return an empty string
    Append the characters to the result string alternatively

Data Structure: 
    hash map to store the frequency of each character
    priority queue to sort the characters based on the frequency

Point to note:
    Retrieve the first most frequent and second most frequent character, append them to the result string, and decrement their frequency. Why? Otherwise, we keep appending the same character to the result.

Algorithm:
    Initialize hash map
    Initialize the most frequent character
    for each character in the string
        increment the frequency of the character
        update the most frequent character
    
    if the most frequent character has a frequency greater than half the length of the string
        return an empty string
    
    Initiliaze a priority queue of pairs of integers and characters
    for each character in the hash map
        push the frequency and character to the priority queue

    reordered <- ""

    while the priority queue has more than one element
        first_frequent <- top element
        pop the top element

        second_frequent <- top element
        pop the top element

        reordered <- reordered + first_frequent.character + second_frequent.__cpp_unicode_characters

        first_frequent.frequency--
        second_frequent.frequency--

        if first_frequent.frequency > 0
            push the first_frequent to the priority queue
        
        if second_frequent.frequency > 0
            push the second_frequent to the priority queue

    if the priority queue is not empty
        first_frequent <- top element
        pop the top element
        
        reordered <- reordered + first_frequent.character
        first_frequent.frequency--

        if first_frequent.frequency > 0
            return an empty string

    return reordered
    

Time Complexity: O(nlogn)

*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>

using namespace std;

class Solution{
    public:
        string reorganizeString(string s){
            int n = s.size();
            string reordered = "";

            unordered_map<char, int> freq;
            int most_frequent = 0;

            for(char c: s){
                freq[c]++;
                most_frequent = max(most_frequent, freq[c]);
            }
            
            if(most_frequent > (n+1)/2)
                return "";
            
            priority_queue<pair<int, char>> pq;

            for(const auto it : freq){
                pq.push({it.second, it.first});
            }        

            while(pq.size() > 1){
                auto one = pq.top();
                pq.pop();
                char c1 = one.second;
                int frequency1 = one.first;

                auto two = pq.top();
                pq.pop();
                char c2 = two.second;
                int frequency2 = two.first;

                reordered = reordered + c1 + c2;
                frequency1--;
                frequency2--;

                if(frequency1 > 0){
                    pq.push({frequency1, c1});
                }
                if(frequency2 > 0){
                    pq.push({frequency2, c2});
                }
            }

            if(!pq.empty()){
                auto it = pq.top();
                char c = it.second;
                int frequency = it.first;
                reordered += c;
                frequency--;

                if(frequency > 0)
                    return "";
            }

            return reordered;
        }

};

int main(){
    Solution s;
    string str = "vvvlo";
    cout<<s.reorganizeString(str)<<endl;

    return 0;
}