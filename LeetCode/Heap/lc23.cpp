/*
LC 23. Merge k Sorted Lists

Ideas: 

Algorithm: 

Time Complexity: 
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}
    
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
class Solution{
    ListNode* combine(ListNode* root, ListNode* ls){
        ListNode* head = new ListNode();
        ListNode* ret = head;

        while(root != nullptr && ls != nullptr){
            if(root->val <= ls->val){
                head->next = root;
                root = root->next;
            }
            else{
                head->next = ls;
                ls = ls->next;
            }

            head = head->next;
        }

        while(root != nullptr){
            head->next = root;
            root = root->next;
            head = head->next;
        }

        while(ls != nullptr){
            head->next = ls;
            ls = ls->next;
            head = head->next;
        }

        return ret->next;
    }

    struct Comparator{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0)
            return nullptr;
        if(n == 1)
            return lists[0];

        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;

        for(ListNode* root : lists){
            if(root)
                pq.push(root);
        }

        if(pq.empty()){
            return nullptr;
        }
        
        ListNode* root = pq.top();
        pq.pop();

        if(root->next)
            pq.push(root->next);

        ListNode* head = root;

        while(!pq.empty()){
            root->next = pq.top();
            pq.pop();

            root = root->next;
            if(root->next){
                pq.push(root->next);
            }
        }

        return head;
    }

};

int main(){
    Solution s;

    return 0;
}