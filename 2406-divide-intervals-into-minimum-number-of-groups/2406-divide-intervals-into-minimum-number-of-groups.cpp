class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        vector<vector<int>> log;
        
        for(int i = 0; i < intervals.size(); i++){
            log.push_back({intervals[i][0], 1});
            log.push_back({intervals[i][1] + 1, -1});
        }
        
        sort(log.begin(), log.end());
        
        int res = 0, cur = 0;
        for(auto &v: log){
            cur += v[1];
            res = max(res, cur);
        }
        return res;
        
    }
};