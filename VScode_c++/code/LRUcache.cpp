#include<unordered_map>
#include<iostream>
using namespace std;
struct DlinkedNode{
    int key ,value;
    DlinkedNode* prev;
    DlinkedNode* next;
    DlinkedNode(): key(0),value(0),prev(nullptr),next(nullptr){}
    DlinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
     unordered_map<int,DlinkedNode*>cache;
     DlinkedNode* head;
     DlinkedNode* tail;
     int size;
     int capacity;


public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DlinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;

    }
    
    void put(int key, int value) {
         if(!cache.count(key)){
             DlinkedNode* node = new DlinkedNode(key,value);
             cache[key] = node;
             addToHead(node);
             ++size;
             if (size > capacity){
                 DlinkedNode* removed = removeTail();
                 cache.erase(removed->key);
                 delete removed;
                 --size;
             }
         }
         else{
             DlinkedNode* node = cache[key];
             node->value = value;
             moveToHead(node);
         }
    }

    void addToHead(DlinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DlinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DlinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
    DlinkedNode* removeTail(){
        DlinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
int main(){
    cout << "hello world" << endl;
    LRUCache  lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4
    cout << 4<< endl;
    getchar();
}