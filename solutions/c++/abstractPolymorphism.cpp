#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};



class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
public:
    LRUCache(int cap){
        capacity = cap;
        check = 0;
        tail = nullptr;
        head = nullptr;
        mp = {};
    }

    void set(int key, int value){

        auto pr = mp.find(key);
        if(pr == mp.end()){
            Node *new_node = new Node(key, value);
            if(check == capacity){
                new_node->next = head;
                head->prev = new_node;
                Node *tmpNode = tail;
                mp.erase(tmpNode->key);
                tail = tail->prev;
                delete tmpNode;

            }
            else if(check < capacity){
                if (head == nullptr) {
                  tail = new_node;
                } else {
                  new_node->next = head;
                  head->prev = new_node;
                }
                check++;
            }
            head = new_node;
            mp.insert(pair<int, Node*>(key, new_node));
        }
        else{
            Node *tmpNode = pr->second;
            if(tmpNode != head){
                    if(tmpNode != tail){
                        (tmpNode->prev)->next = tmpNode->next;
                        tmpNode->next->prev = tmpNode->prev;
                    }else{
                        tail = tmpNode->prev;
                        tmpNode->prev->next = nullptr;
                    }
                    tmpNode->prev = nullptr;
                    tmpNode->next = head;
                    head->prev = tmpNode;
                    head = tmpNode;
            }
            head->value = value;
        }
    }
    int get(int a){
        return  ((mp.find(a) != mp.end()) ? mp[a]->value: -1);
    }

private:
    int capacity;
    int check;
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
