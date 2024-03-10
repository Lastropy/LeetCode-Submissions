class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        int n = a.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            pq.push(a[i]);
        }
        while(k){
            auto tp = pq.top(); pq.pop();
            pq.push(tp * - 1);
            k--;
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};