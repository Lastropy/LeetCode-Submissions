class Solution {
public:
    void dfs(unordered_map<string, multiset<string>> &g, vector<string> &ans, string st){
        while(!g[st].empty()){
            string next = *g[st].begin();
            g[st].erase(g[st].begin());
            dfs(g, ans, next);
        }
        ans.push_back(st);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> g;
        for(auto v: tickets)
            g[v[0]].insert(v[1]);
        vector<string> ans;
        dfs(g, ans, "JFK");
        reverse(begin(ans), end(ans));
        return ans;
    }
};