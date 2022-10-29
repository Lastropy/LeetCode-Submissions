class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n = p.size();
        vector<vector<int>> log;
        for(int i = 0 ; i <n ;i++){
            log.push_back({g[i], p[i]});
        }
        
        sort(log.begin(), log.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] > b[0];
        });
        
        int curr = 0, ans = INT_MIN;
        for(auto l: log){
            curr += l[1];
            ans = max(ans, curr + l[0]);
        }
        return ans;
    }
};