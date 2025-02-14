#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Trie{
        struct TrieNode{
            bool isWord = false;
            vector<TrieNode*> child = vector<TrieNode*>(26, nullptr);
        };

        TrieNode *root, *current;

        void dfs(TrieNode* curr, string& prefix, vector<string>& sugg){
            if(sugg.size() == 3)
                return;

            if(curr->isWord)
                sugg.push_back(prefix);

            for(char c = 'a'; c <= 'z'; c++){
                if(curr->child[c-'a']){
                    prefix += c;
                    dfs(curr->child[c-'a'], prefix, sugg);
                    prefix.pop_back();
                }
            }
        }

    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string& word){
            current = root;
            for(auto& w : word){
                int index = w - 'a';
                if(!current->child[index])
                    current->child[index] = new TrieNode();
                current = current->child[index];
            }
            current->isWord = true;
        }

        vector<string> getWords(string& prefix){
            current = root;
            vector<string> sugg;

            for(auto& p : prefix){
                int index = p - 'a';
                if(!current->child[index])
                    return sugg;
                current = current->child[index];
            }

            dfs(current, prefix, sugg);
            return sugg;
        }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> sugg;

        Trie trie = Trie();

        for(auto& product : products){
            trie.insert(product);
        }

        string prefix;
        for(auto& w : searchWord){
            prefix += w;
            sugg.push_back(trie.getWords(prefix));
        }
        
        return sugg;
    }
};