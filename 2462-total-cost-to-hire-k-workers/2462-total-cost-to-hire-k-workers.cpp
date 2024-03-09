class Solution {
public:
    long long totalCost(vector<int>& a, int k, int c) {
        long long ans = 0;
        int n = a.size();
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int pos1 =0, pos2 = n - 1;
        while(k){
            if(pos1 <= pos2 && pq1.size() < c) {
                pq1.push(a[pos1++]);
            }
            else if(pos1 <= pos2 && pq2.size() < c){
                pq2.push(a[pos2--]);
            }
            else {
                if(pq1.empty() && pq2.empty()) return ans;
                else if(pq1.empty()) {
                    ans += pq2.top();
                    pq2.pop();
                } else if(pq2.empty()) {
                    ans += pq1.top();
                    pq1.pop();
                } else {
                    if(pq1.top() <= pq2.top()){
                        ans += pq1.top();
                        pq1.pop();
                    } else {
                        ans += pq2.top();
                        pq2.pop();
                    }
                }
                k--;
            }
        }
        return ans;
    }
};