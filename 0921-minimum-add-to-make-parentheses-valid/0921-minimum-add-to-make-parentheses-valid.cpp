class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else {
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        return st.size();
    }
};