/*  
Class node is there to store nodes of a Doubly Linked List.
DLL has head and tail.
It contains prev, next, key and value.
A map will be used to store the node location by key value.
When a node is inserted/accessed, it becomes RECENTLY USED.
DLL is ordered such that the most RECENTLY USED key value node is near the head and least recently used node is near the tail.
Insert always happens at head ( most recently used )
Deletion always happens at tail ( least recently used )
*/
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
    /** initial DLL**/
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m;
    
    /** DLL function - addNode **/
    void addNode(node *newNode){
        node *temp = head -> next;
        
        newNode -> prev = head;
        head -> next = newNode;
        
        newNode -> next = temp;
        temp -> prev = newNode;
    }
    
    /** DLL function - deleteNode **/
    void deleteNode(node *n){
        auto prevN = n -> prev;
        auto nextN = n -> next;
        if(prevN) prevN -> next = nextN;
        if(nextN) nextN -> prev = prevN;
        delete n;
    }
    
    /** intialize LRUcache **/
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    
    /** 
        get a key's value if present
        else return -1.
        if present, delete existing node and move it next to head 
    **/
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
    
    /** 
        if key node already present, delete it.
        if capacity full, delete from tail (LRU)
        add node to head (most recently used)
        add to map
    **/
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