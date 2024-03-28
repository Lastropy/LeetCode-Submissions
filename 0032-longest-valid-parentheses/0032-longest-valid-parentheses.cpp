class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            } else st.push(i);
        }
        
        int ans = 0, end = n;
        while(!st.empty()){
            ans = max(ans, (end - st.top() - 1));
            end = st.top();
            st.pop();
        }
        ans = max(ans, end);
        return ans;
    }
};