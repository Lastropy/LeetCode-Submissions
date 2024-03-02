class Solution {
public:
    string removeStars(string s) {
        int lc = 0, i = 0;
        stack<int> st;
        while(i < s.size()){
            if(s[i] != '*'){
                st.push(i);
            } else {
                int tp = st.top();
                st.pop();
                s[tp] = '_';
                s[i] = '_';
            }
            i++;
        }
        string ans = "";
        for(char c: s){
            if(c != '_') ans += c;
        }
        return ans;
    }
};