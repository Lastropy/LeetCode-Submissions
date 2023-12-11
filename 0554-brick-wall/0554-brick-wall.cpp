class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for(auto v: wall){
            int end = 0;
            for(int i = 0; i < v.size() - 1; i++){
                end += v[i];
                mp[end]++;
            }
        }
        int ans = wall.size();
        for(auto [k,v]: mp){
            int touched = wall.size() - v;
            ans = min(touched, ans);
        }
        return ans;
    }
};