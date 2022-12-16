class MyQueue {
private: 
    void transfer(stack<int> &s, stack<int> &t){
        if(!t.empty()) return;
        for(;!s.empty(); s.pop())
            t.push(s.top());
    }
public:
    stack<int> q1,q2;   
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q2.empty()) transfer(q1, q2);
        if(q2.empty()) return -1;
        int ans = q2.top();
        q2.pop();
        return ans;
    }
    
    int peek() {
        if(q2.empty()) transfer(q1, q2);
        if(q2.empty()) return -1;
        return q2.top();
    }
    
    bool empty() {
        return (q2.empty() && q1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */