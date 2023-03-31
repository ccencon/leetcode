/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class LRUCache {
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };
    int _capacity;
    int _count = 0;
    Node* _head = nullptr;
    Node* _tail = nullptr;
    unordered_map<int, Node*> kvAddr;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    void refreshCache(Node* addr){
        if(addr == _head)
            return;
        addr->prev->next = addr->next;
        if(addr == _tail)
            _tail = addr->prev;
        else
            addr->next->prev = addr->prev;
        addr->prev = nullptr;
        addr->next = _head;
        _head->prev = addr;
        _head = addr;
    }

    int get(int key) {
        unordered_map<int, Node*>::iterator it = kvAddr.find(key);
        if(it == kvAddr.end())
            return -1;
        refreshCache(it->second);
        return it->second->val;
    }
    
    void put(int key, int value) {
        unordered_map<int, Node*>::iterator it = kvAddr.find(key);
        if(it != kvAddr.end()){
            it->second->val = value;
            refreshCache(it->second);
            return;
        }
        if(_count >= _capacity){
            kvAddr.erase(_tail->key);
            _tail->key = key;
            _tail->val = value;
            kvAddr[key] = _tail;
            refreshCache(_tail);
        }
        else{
            Node* addr = new Node(key, value);
            kvAddr[key] = addr;
            _count++;
            if(!_head)
                _head = _tail = addr;
            else{
                addr->next = _head;
                _head->prev = addr;
                _head = addr;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

