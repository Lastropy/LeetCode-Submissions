class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> st;
        int n = a.size();
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
            else w = n - (st.top()) - 1;
            ans = max(ans, h * w);
        }
        return ans;
    }
};