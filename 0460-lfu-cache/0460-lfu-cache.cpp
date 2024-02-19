class node {
public:
    int key;
    int val;
    int cnt;
    node *prev = NULL;
    node *next = NULL;
    node(int _key, int _val, int _cnt = 1){
        this -> key = _key;
        this -> val = _val;
        this -> cnt = _cnt;
    }
};

class DLL {
public:
    node *head;
    node *tail;
    int size;

    DLL(){
        this -> size = 0;
        this -> head = new node(-1, -1);
        this -> tail = new node(-1, -1);
        this -> head -> next = this -> tail;
        this -> tail -> prev = this -> head;
    }

    void addNode(node *n){
        node *t = head -> next;
        n -> prev = head;
        n -> next = t;
        head -> next = n;
        t -> prev = n;
        size++;
    }
    
    void removeNode(node *n){
        node *nPrev = n -> prev, *nNext = n -> next;
        if(nNext) nNext -> prev = nPrev;
        if(nPrev) nPrev -> next = nNext;
        delete n;
        size--;
    }
};

class LFUCache {
private:
    map<int, node*> keyNode;
    map<int, DLL*> freqList;
    int maxCacheSize;
    int minFreq;
    int currSize;
    
    void update_frequency_list_map(node *n){
        int key = (n -> key), val = (n -> val), cnt = (n -> cnt);
        keyNode.erase(key);
        freqList[cnt] -> removeNode(n);
        if(cnt == minFreq && freqList[cnt] -> size == 0)
            minFreq++;
        
        auto nextList = new DLL();
        if(freqList.count(cnt + 1))
            nextList = freqList[cnt + 1];
        
        cnt += 1;
        nextList -> addNode(new node(key, val, cnt));
        freqList[cnt] = nextList;
        keyNode[key] = nextList -> head -> next;
    }
public:
    LFUCache(int capacity) {
        this -> maxCacheSize = capacity;
        this -> currSize = 0;
        this -> minFreq = 0;
    }
    
    int get(int key) {
        if(keyNode.count(key)){
            node *n = keyNode[key];
            int val = n -> val;
            update_frequency_list_map(n);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize == 0) return;
        if(keyNode.count(key)){
            auto n = keyNode[key];
            n -> val = value;
            update_frequency_list_map(n);
            return;
        } 
        
        if(currSize == maxCacheSize){
            auto lst = freqList[minFreq];
            keyNode.erase(lst -> tail -> prev -> key);
            lst -> removeNode(lst -> tail -> prev);
            currSize--;
        }
        
        currSize++;
        
        minFreq = 1;
        auto minFreqList = new DLL();
        if(freqList.count(minFreq))
            minFreqList = freqList[minFreq];
        
        auto newNode = new node(key, value);
        keyNode[key] = newNode;
        minFreqList -> addNode(newNode);
        freqList[minFreq] = minFreqList;
    }
};