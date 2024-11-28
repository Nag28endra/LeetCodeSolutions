class LRUCache {
    // class for creating node.
    public:
        class Node{
            public: 
                int key;
                int value;
                Node* prev;
                Node* next;
                Node(int k, int v){
                    key = k;
                    value = v;
                }
        };
public:
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node *> mpp; 
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }
    void deleteNode(Node* existingNode){
        Node* prevNode = existingNode->prev;
        Node* nextNode = existingNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    int get(int key) {
        if (mpp.find(key)!=mpp.end()){
            Node* resNode = mpp[key];
            int res = resNode->value;
            mpp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key)!=mpp.end()){
            Node* existingNode = mpp[key];
            mpp.erase(key);
            deleteNode(existingNode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */