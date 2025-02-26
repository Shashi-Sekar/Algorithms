/*
LC 706. Design HashMap

We use Chaining to handle collisions.

*/

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int key;
    int value;

    Node* next;

    Node(): key(-1), value(-1), next(nullptr) {}
    Node(int key, int value): key(key), value(value), next(nullptr) {}
};

class HashMap{
    vector<Node*> hashTable;
    int size = 1000;
    public:
        HashMap(){
            hashTable = vector<Node*>(size, nullptr);
        }

        int hash(int key){
            return key % size;
        }

        void put(int key, int value){
            int index = hash(key);

            Node* current = hashTable[index];

            if(current == nullptr){
                hashTable[index] = new Node();
                current = hashTable[index];
            }

            while(current->next != nullptr){
                if(current->next->key == key){
                    current->next->value = value;
                    return;
                }
                current = current->next;
            }
            
            current->next = new Node(key, value);
            return;
        }

        int get(int key){
            int index = hash(key);
            Node* current = hashTable[index];

            if(current == nullptr)
                return -1;
            
            while(current->next != nullptr){
                if(current->next->key == key)
                    return current->next->value;
                current = current->next;
            }

            return -1;
        }

        void remove(int key){
            int index = hash(key);
            Node* current = hashTable[index];

            if(current == nullptr)
                return;
            
            while(current->next != nullptr){
                if(current->next->key == key){
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }

            return;
        }
};

int main(){
    HashMap hm;

    return 0;
}
