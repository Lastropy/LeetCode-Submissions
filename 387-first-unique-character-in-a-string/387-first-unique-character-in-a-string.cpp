class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int>> mp;
        for(int i  = 0; i < s.size(); i++)
            mp[s[i]].push_back(i);
        int ans = INT_MAX;
        for(auto [k, v]: mp){
            if(v.size() == 1)
                ans  = min(ans, v[0]);
        }
        return ans == INT_MAX ? -1: ans;
    }
};