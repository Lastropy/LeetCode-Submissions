class Solution {
public:
    bool isValid(string &s){
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') continue;
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty() || s[st.top()] == ')')
                    st.push(i);
                else
                    st.pop();
            }
        }
        return (st.empty());
    }
    
    vector<string> removeInvalidParentheses(string s) {
        if(isValid(s)) return {s};
        vector<string> ans;
        queue<string> q;
        q.push(s);
        unordered_set<string> st1;        
        unordered_set<string> st2;

        while(!q.empty()){
            int siz = q.size();
            for(int i = 0; i < siz; i++){
                auto tp = q.front(); q.pop();
                for(int i = 0; i < tp.size(); i++){
                    if(tp[i] >= 'a' && tp[i] <= 'z') continue;
                    auto newStr = tp.substr(0,i) + tp.substr(i + 1);
                    if(st2.find(newStr) == st2.end()){
                        q.push(newStr);
                        st2.insert(newStr);
                    }
                    if(isValid(newStr)){
                        if(st1.find(newStr) == st1.end()){
                            ans.push_back(newStr);
                            st1.insert(newStr);
                        }
                    }
                }
            }
            if(ans.size()) {
                return ans;
            }
        }
        return {""};
    }
};