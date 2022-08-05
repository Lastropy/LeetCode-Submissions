class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> g;
        for(auto v: tickets)
            g[v[0]].insert(v[1]);
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        
        while(!st.empty()){
            string src = st.top();
            if(g[src].empty()){
                ans.push_back(src);
                st.pop();
            }
            else
            {
                st.push(*g[src].begin());
                g[src].erase(g[src].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};