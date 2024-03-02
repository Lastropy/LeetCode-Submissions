class MinHeap {
public:
    vector<int> heap;
    int sz;
    
    MinHeap(int cap){
        heap = vector<int>(cap, -1);
        sz = 0;
    }
    
    void buildHeapFromArray(int n){
        sz = n;
        for(int i = 0; i < sz; i++){
            heap[i] = i+1;
        }
        int startIdx = (sz - 1)/2;
        for(int i = startIdx; i >= 0; i--){
             topDownMinHeapify(i);
        }
    }
        
    int parent(int pos) {
        return ((pos - 1)/ 2);
    }
    
    int leftChild(int pos) {
        return (2 * pos + 1);
    }
    
    int rightChild(int pos) {
        return (2 * pos + 2);
    }
     
    // Top 
    void push(int ele){
        heap[sz] = ele;
        bottomUpMinHeapify(sz);
        sz++;
    }
    
    int pop() {
        int val = heap[0];
        sz--;
        if(sz > 0) {
            swap(heap[0], heap[sz]);
            topDownMinHeapify(0);
        }
        return val;
    }
    
    void bottomUpMinHeapify(int idx){
        int ch = idx;
        while(ch != 0 && heap[parent(ch)] > heap[ch])
        {
            swap(heap[parent(ch)], heap[ch]);
            ch = parent(ch);
        }
    }
    
    void topDownMinHeapify(int pos){
        int p = pos;
        while(p < sz) {
            int l = leftChild(p), r = rightChild(p);
            int smallest = p;
            if(l < sz && heap[l] < heap[smallest]) smallest = l;
            if(r < sz && heap[r] < heap[smallest]) smallest = r;
            if(smallest != p) swap(heap[smallest], heap[p]);
            else break;
            p = smallest;
        }
    }
};

class SeatManager {
public:
    MinHeap *h;
    SeatManager(int n) {
        h = new MinHeap(n);
        // // Top Down approach to make Heap from array
        // for(int i = 0; i < n; i++){
        //     h -> push(i+1);
        // }
        
        // Bottom Up approach to make Heap from array
        h -> buildHeapFromArray(n);
    }
    
    int reserve() {
        int seatNum = h -> pop();
        return seatNum;
    }
    
    void unreserve(int seatNumber) {
        h -> push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */