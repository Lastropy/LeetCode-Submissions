class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<vector<int>> r, l;
        int n = h.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            while(!l.empty() && l.top()[0] >= h[i])
                l.pop();
            if(l.empty()) {
                ans[i] += (i + 1) * h[i];
            } else {
                ans[i] += (i - (l.top()[1])) * h[i];
            }
            l.push({h[i], i});
        }
        
        for(int i = n - 1; i >= 0; i--){
            while(!r.empty() && r.top()[0] >= h[i])
                r.pop();
            if(r.empty()) {
                ans[i] += (n - 1 - i) * h[i];
            } else {
                ans[i] += ((r.top()[1]) - i - 1) * h[i];
            }
            r.push({h[i], i});
        }
        
        return *max_element(ans.begin(), ans.end());
        
    }
};