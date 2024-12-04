#include <unordered_map>
using namespace std;

// Creating a node
struct Node {
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        value = v;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

// Creating a doubly linked list
struct List {
    int size;
    Node* head;
    Node* tail;
    
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Function to add a node right after the head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        size++;
    }

    // Function to delete the current node
    void removeNode(Node* existingNode) {
        Node* prevNode = existingNode->prev;
        Node* nextNode = existingNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode; // Hash map to store key and node address
    unordered_map<int, List*> freqHash; // Hash map to store frequency and corresponding list
    int cache_current_size;
    int max_cache_capacity;
    int minFreq;

public:
    LFUCache(int capacity) {
        max_cache_capacity = capacity;
        minFreq = 0;
        cache_current_size = 0;
    }

    void updateFreqList(Node* node) {
        // Remove the node from the key-node hash map
        keyNode.erase(node->key);

        // Remove the node from the frequency list
        freqHash[node->cnt]->removeNode(node);

        // Update the minimum frequency if the current frequency list becomes empty
        if (node->cnt == minFreq && freqHash[node->cnt]->size == 0) {
            minFreq++;
        }

        // Update the frequency of the node
        node->cnt++;

        // Add the node to the next frequency list
        List* nextFreqList;
        if (freqHash.find(node->cnt) != freqHash.end()) {
            nextFreqList = freqHash[node->cnt];
        } else {
            nextFreqList = new List();
            freqHash[node->cnt] = nextFreqList;
        }
        nextFreqList->addNode(node);

        // Update the key-node hash map
        keyNode[node->key] = node;
    }

    int get(int key) {
        // Check whether the key is present in the key-node hash map
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        if (max_cache_capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        } else {
            if (cache_current_size == max_cache_capacity) {
                List* list = freqHash[minFreq];
                if (list->size > 0) {
                    Node* toRemove = list->tail->prev;
                    keyNode.erase(toRemove->key);
                    list->removeNode(toRemove);
                }
                cache_current_size--;
            }

            cache_current_size++;
            minFreq = 1;

            List* list;
            if (freqHash.find(minFreq) != freqHash.end()) {
                list = freqHash[minFreq];
            } else {
                list = new List();
                freqHash[minFreq] = list;
            }

            Node* node = new Node(key, value);
            list->addNode(node);
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */