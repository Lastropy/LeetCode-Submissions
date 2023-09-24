class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        stack <int>st;
        int n = h.size();
        vector<long long> left_sum(n, 0), right_sum(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            if(st.empty())
                left_sum[i] = 1ll * (i + 1) * h[i];
            else 
                left_sum[i] = 1ll * (i - st.top())* h[i] + left_sum[st.top()];
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            if(st.empty())
                right_sum[i] = 1ll * (n-i) * h[i];
            else
                right_sum[i] = 1ll * (st.top()  - i) * h[i] + right_sum[st.top()];
            st.push(i);
        }
        long long ans = 0;
        for(int i =0; i < n; i++)
            ans  = max(ans, left_sum[i] + right_sum[i] - h[i]);
        return ans;
    }
};