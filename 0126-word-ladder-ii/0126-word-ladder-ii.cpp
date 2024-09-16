class Solution {
public:
    unordered_map<string, int> mp;
    int findMinLadderSize(string b, string e, vector<string>& a, unordered_set<string> &st) {
        int n = a.size(), m = b.size();        
        queue<string> q;
        q.push(b);   
        mp[b] = 1;
        int ans = 1;
        while(!q.empty()){
            int siz = q.size();
            ans++;
            for(int i = 0; i< siz; i++){
                auto tp = q.front(); q.pop();
                int steps = mp[tp];
                if(tp == e) return ans;
                for(int j = 0; j < m; j++){
                    char org = tp[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        tp[j] = c;
                        if(st.find(tp) != st.end()){
                            q.push(tp);
                            st.erase(tp);
                            mp[tp] = steps+1;
                        }
                    }
                    tp[j] = org;
                }
            }
        }
        return 1e9; 
    }
    
    void dfs(string &b, string e, int maxDepth, vector<string> &curr, vector<vector<string>> &ans){
        if(b == e) {
            reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            reverse(curr.begin(), curr.end());
        }
        if(maxDepth <= 1) return;
        
        int lvl = mp[e];
        for(int i = 0; i < e.size(); i++){
            char org = e[i];
            for(char c = 'a'; c <= 'z'; c++){
                e[i] = c;
                if(mp.count(e) && mp[e] == lvl - 1){
                    curr.push_back(e);
                    dfs(b, e, maxDepth - 1, curr, ans);
                    curr.pop_back();
                }
            }
            e[i] = org;
        }
    }
    
    vector<vector<string>> findLadders(string b, string e, vector<string>& a) {
        unordered_set<string> st(a.begin(), a.end());
        st.erase(b);
        int maxDepth = findMinLadderSize(b, e, a, st);
        vector<vector<string>> ans;
        if(maxDepth == 1e9) return ans;
        vector<string> curr;
        curr.push_back(e);
        dfs(b, e, maxDepth, curr, ans);
        return ans;
    }
};