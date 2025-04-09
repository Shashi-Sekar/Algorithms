/*
Least Frequently Used Cache
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node{
    /*
    Represents a node in the doubly linked list
    Attributes:
        key: the key of the element, int
        value: the value of the element, int
        prev: pointer to the previous node in the access order, Node*
        next: pointer to the next node in the access order, Node*
    */

    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

class LRUCache{
    /*
    Least Recently Used Cache
    Attributes:
        capacity: the maximum number of elements the cache can store, int
        oldest: (Sentinel node) the oldest node (least recently used), towards the left  
        newest: (Sentinel node) the newest node (most recently used), towards the right

        oldest ->least_recently_used_node1 -> least_recently_used_node2 -> ... -> most_recently_used_node1 -> most_recently_used_node2 -> newest

        cache: a map of key to node, unordered_map<int, Node*>
    */
    
    int capacity;
    Node* oldest = new Node(-1, -1);
    Node* newest = new Node(-1, -1);
    unordered_map<int, Node*> cache;

    public:
        LRUCache(int capacity) {
            /*
            Constructor
            */
            this->capacity = capacity;
            oldest->next = newest;
            newest->prev = oldest;
        }

        ~LRUCache(){
            /*
            Destructor - deallocate memory for the nodes
            */
            Node* current = oldest;

            while(current != nullptr){
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        
        void addNode(Node* current_newest){
            /*
            Add a node to the newest end of the doubly linked list
            */
            
            //Get the node that the newest sentinel is pointing to
            Node* prev_newest = newest->prev;

            //The newest node is added to the right of the prev_newest node
            prev_newest->next = current_newest;
            current_newest->prev = prev_newest;

            //The newest node is added to the left of the newest sentinel
            current_newest->next = newest;
            newest->prev = current_newest;

        }

        void deleteNode(Node* node){
            /*
            Delete the given node from the doubly linked list
            */

            //Get the previous and next nodes of the given node
            Node* prev_node = node->prev;
            Node* next_node = node->next;

            //The previous node is now pointing to the next node
            prev_node->next = next_node;
            next_node->prev = prev_node;

        }

        int get(int key) {
            //If the key is not in the cache, return -1
            if(cache.find(key) == cache.end()){
                return -1;
            }

            //Get the requested node
            Node* requested_node = cache[key];

            //Move the requested node to the newest end of the doubly linked list
            deleteNode(requested_node);
            addNode(requested_node);

            //Return the value of the requested node
            return requested_node->value;
        }
        
        void put(int key, int value) {

            //If the key is already in the cache, delete the node
            if(cache.find(key) != cache.end()){
                Node* update_node = cache[key];
                deleteNode(update_node);
                cache.erase(key);
            }
            
            //If the cache is full, delete the oldest node
            if(cache.size() == this->capacity){
                //Oldest node is pointed to by the oldest sentinel
                Node* delete_node = oldest->next;
                
                deleteNode(delete_node);
                cache.erase(delete_node->key);

                //Deallocate memory for the deleted node
                delete delete_node;
            }

            //Add the new node to the cache
            Node* new_node = new Node(key, value);
            addNode(new_node);
            cache[key] = new_node;
        }
};

class LFUCache : public LRUCache{
    int leastFrequency;
    unordered_map<int, int> frequency;
    
    
};

int main(){
    return 0;
}