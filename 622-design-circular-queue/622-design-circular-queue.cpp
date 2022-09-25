class MyCircularQueue {
public:
    int *a;
    int size, r, f;

    MyCircularQueue(int k) {
        a = new int[k];
        size = k;
        f = 0;
        r = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        r = (r + 1) % size;
        a[r] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(f == r){ f = 0; r  = -1;}
        else f = (f+1) % size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : a[f];
    }
    
    int Rear() {
        return isEmpty() ? -1 : a[r];
    }
    
    bool isEmpty() {
        return r == -1;
    }
    
    bool isFull() {
        return !isEmpty() && (r + 1) % size == f;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */