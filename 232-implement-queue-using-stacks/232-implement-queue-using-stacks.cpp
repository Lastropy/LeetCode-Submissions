class MyQueue {
private: 
    void transfer(stack<int> &s, stack<int> &t){
        for(;!s.empty(); s.pop())
            t.push(s.top());
    }
public:
    stack<int> q1,q2;   
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(empty()) return -1;
        if(q2.empty()) transfer(q1, q2);
        int ans = q2.top();
        q2.pop();
        return ans;
    }
    
    int peek() {
        if(empty()) return -1;
        if(q2.empty()) transfer(q1, q2);
        return q2.top();
    }
    
    bool empty() {
        return (q2.empty() && q1.empty());
    }
};