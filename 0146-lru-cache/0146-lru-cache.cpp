class node {
    public:
        node *prev = NULL;
        node *next = NULL;
        int key;
        int val;
        node(int _key,int _val){
            this -> key = _key;
            this -> val = _val;
        }
};

class LRUCache {
public:
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m;
    
    void addNode(node *newNode){
        node *temp = head -> next;
        
        newNode -> prev = head;
        head -> next = newNode;
        
        newNode -> next = temp;
        temp -> prev = newNode;
    }

    void deleteNode(node *n){
        auto prevN = n -> prev;
        auto nextN = n -> next;
        if(prevN) prevN -> next = nextN;
        if(nextN) nextN -> prev = prevN;
        delete n;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    
    int get(int _key) {
        if(m.count(_key)){
            auto n = m[_key];
            int val = n -> val;
            m.erase(_key);
            deleteNode(n);
            addNode(new node(_key, val));
            m[_key] = head -> next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            node *existingN = m[key];
            m.erase(key);
            deleteNode(existingN);
        }
        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        addNode(new node(key, value));
        m[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */