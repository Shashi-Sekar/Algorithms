#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TrieNode{
    bool isWord = false;
    vector<TrieNode*> child = vector<TrieNode*>(26, nullptr);
};

class Trie{
    TrieNode* root;

    //DFS
    void dfs(TrieNode* current, string prefix, vector<string>& suggestions, int k){
        if(suggestions.size() == k)
            return;
        
        if(current->isWord){
            suggestions.push_back(prefix);
        }
        
        for(char c = 'a'; c <= 'z'; c++){
            if(current->child[c-'a']){
                dfs(current->child[c-'a'], prefix+c, suggestions, k);
            }
        }

        return;
    }

    public:
        Trie(){
            root = new TrieNode();
        }

        //insert
        void insert(string& word){
            TrieNode* current = root;
            for(char w: word){
                int index = w - 'a';
                if(!current->child[index])
                    current->child[index] = new TrieNode();
                current = current->child[index];
            }
            current->isWord = true;
        }

        //getWords
        vector<string> getWords(string& searchWord, int k){

            vector<string> suggestions;

            //Traversing until the end of searchWord
            TrieNode* current = root;
            for(char w: searchWord){
                int index = w - 'a';
                if(!current->child[index])
                    return suggestions;
                current = current->child[index];
            }

            //DFS to get the first k words
            dfs(current, searchWord, suggestions, k);
            return suggestions;
        }
};

int main(){
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";

    Trie trie = Trie();

    for(string product: products){
        trie.insert(product);
    }

    vector<vector<string>> suggestions;
    string prefix = "";

    for(char w: searchWord){
        prefix += w;
        suggestions.push_back(trie.getWords(prefix, 3));
    }

    for(auto suggestion: suggestions){
        for(string s: suggestion){
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;    
}