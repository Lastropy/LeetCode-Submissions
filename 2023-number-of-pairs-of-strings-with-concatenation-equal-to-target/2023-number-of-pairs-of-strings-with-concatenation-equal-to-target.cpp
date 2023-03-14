class Solution {
public:
    int numOfPairs(vector<string>& a, string t) {
        unordered_map<string, int> mp;
        int n = a.size(), ans = 0;
        
        for(string i: a){
            if(i.size() < t.size())
                mp[i]++;
        }
        
        
        for(auto [s, freq]: mp){
            if(t.find(s) == 0){
                if(s + s == t)
                    ans += freq * (freq - 1);
                else
                    ans += freq * mp[t.substr(s.size())];
            }
        }
        return ans;
    }
};