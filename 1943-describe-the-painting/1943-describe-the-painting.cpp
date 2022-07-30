class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long> log;
        for(auto s: segments){
            log[s[0]] += s[2];
            log[s[1]] -= s[2];
        }
        vector<vector<long long>> ans;
        long now = 0;
        auto it2 = log.begin(); advance(it2, 1);
        for(auto it = log.begin(); it2 != log.end(); it++, advance(it2, 1)){
            now += it -> second;
            if(now)
                ans.push_back({it -> first, it2 -> first, now});
        }
        return ans;
    }
};