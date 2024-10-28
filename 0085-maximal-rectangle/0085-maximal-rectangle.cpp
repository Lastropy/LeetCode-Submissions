class Solution {
public:
    int maxAreaRectangleInHistogram(vector<int> &a, int n){
        stack<int> st;
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            while(!st.empty() && a[st.top()] > a[i]){
                int h = a[st.top()], w = 0; st.pop();
                if(st.empty()) w = i;
                else w = i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int h = a[st.top()], w = 0; st.pop();
            if(st.empty()) w = n;
            else w = n - st.top() - 1;
            ans = max(ans, h * w);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> h(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            ans = max(ans, maxAreaRectangleInHistogram(h, m));
        }
        return ans;
    }
};