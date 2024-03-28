class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<vector<int>> st;
        int n = h.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top()[0] >= h[i])
                st.pop();
            if(st.empty()) {
                ans[i] += (i + 1) * h[i];
            } else {
                ans[i] += (i - (st.top()[1])) * h[i];
            }
            st.push({h[i], i});
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top()[0] >= h[i])
                st.pop();
            if(st.empty()) {
                ans[i] += (n - 1 - i) * h[i];
            } else {
                ans[i] += ((st.top()[1]) - i - 1) * h[i];
            }
            st.push({h[i], i});
        }
        
        return *max_element(ans.begin(), ans.end());
        
    }
};