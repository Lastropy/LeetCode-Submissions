class Solution {
public:
    int findMaxPath(vector<vector<int>> &adj, string &s, int node, int &ans){
        int t1 = 0, t2 = 0;
        for(int& child: adj[node]){
            int temp = findMaxPath(adj, s, child, ans);
            if(s[node] == s[child]) continue;
            if(temp > t2) t2 = temp;
            if(t2 > t1) swap(t1, t2);
        }
        ans = max(ans, t1 + t2 + 1);
        return 1 + t1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), ans = 0;
        vector<vector<int>> adj(n);
        
        for(int node = 1; node < n; node++)
            adj[parent[node]].push_back(node);
    
        findMaxPath(adj,s, 0,ans);
        return ans;
    }

//     int longestPath(vector<int>& parent, string s) {
//         int n = s.size(), res = 0;
//         vector<vector<int>> children(n, vector<int>());
//         for (int i = 1; i < n; ++i)
//             children[parent[i]].push_back(i);
//         dfs(children, s, res, 0);
//         return res;
//     }

//     int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
//         int big1 = 0, big2 = 0;
//         for (int& j : children[i]) {
//             int cur = dfs(children, s, res, j);
//             if (s[i] == s[j]) continue;
//             if (cur > big2) big2 = cur;
//             if (big2 > big1) swap(big1, big2);
//         }
//         res = max(res, big1 + big2 + 1);
//         return big1 + 1;
//     }
};