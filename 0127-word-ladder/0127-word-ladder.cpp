class Solution {
public:
   int ladderLength(string b, string e, vector<string>& a) {
        int n = a.size(), m = b.size();
        unordered_set<string> st(a.begin(), a.end());
        st.erase(b);        
        queue<string> q;
        q.push(b);   
        int ans = 1;
        while(!q.empty()){
            int siz = q.size();
            ans++;
            for(int i = 0; i< siz; i++){
                auto tp = q.front(); q.pop();
                for(int j = 0; j < m; j++){
                    char org = tp[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        tp[j] = c;
                        if(st.find(tp) != st.end()){
                            if(tp == e) return ans;
                            q.push(tp);
                            st.erase(tp);
                        }
                    }
                    tp[j] = org;
                }
            }
        }
        return 0;
        
    }
};