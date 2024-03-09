class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxheap.size() == 0) {
            maxheap.push(num);
        } else if(maxheap.size() == minheap.size()){
            if(num < minheap.top()){
                maxheap.push(num);
            } else {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }
        } else {
            if(minheap.size() == 0){
                if(num > maxheap.top()){
                    minheap.push(num);
                } else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                }
            } else if(num >= minheap.top()){
                minheap.push(num);
            } else {
                if(num >= maxheap.top()){
                    minheap.push(num);
                } 
                else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(maxheap.size() > minheap.size()) {
            return maxheap.top();
        }
        double ans = maxheap.top() + minheap.top();
        return (ans / 2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */