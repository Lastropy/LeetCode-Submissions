class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n = p.size();
        vector<vector<int>> log;
        for(int i = 0 ; i <n ;i++){
            log.push_back({g[i], p[i]});
        }
        
        sort(log.rbegin(), log.rend());
        // , [&](vector<int> &a, vector<int> &b){
        //     return a[0] > b[0];
        // });
        
        int curr = 0, ans = INT_MIN;
        for(auto l: log){
            int pt = l[1], gt = l[0];
            ans = max(ans, curr + pt + gt);
            curr += pt;
        }
        return ans;
    }
};