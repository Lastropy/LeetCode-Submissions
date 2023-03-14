class Solution {
public:
    int numOfPairs(vector<string>& a, string t) {
        unordered_map<string, int> mp;
        int n = a.size(), ans = 0;
        
        for(int i = 0; i< n; i++){
            if(t.find(a[i]) == 0)
                ans += mp[t.substr(a[i].size())];
            if(t.rfind(a[i]) == t.size() - a[i].size())
                 ans += mp[t.substr(0,  t.size() - a[i].size())];
            mp[a[i]]++;
        }
        return ans;
    }
};