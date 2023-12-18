class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        long long pref_sum = 0;
        int ans = INT_MAX;
        
        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long, int>>> min_heap;
        min_heap.push({0, -1});
        
        
        for(int i = 0; i < n; i++){
            pref_sum += a[i];
            while(!min_heap.empty() && pref_sum - min_heap.top().first >= k){
                ans = min(ans, i - min_heap.top().second);
                min_heap.pop();
            }
            min_heap.push({pref_sum, i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};