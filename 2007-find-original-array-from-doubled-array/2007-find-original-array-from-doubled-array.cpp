class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2) return {};

        vector<int> ans;

        unordered_map<int, int> mp;
        for(int e: changed) mp[e]++;
        
        vector<int> keys;
        for(auto [k,v] : mp) keys.push_back(k);
        
        sort(begin(keys), end(keys), [&](int a, int b){
            return abs(a) < abs(b);
        });

        for(int x: keys){
            if(mp[x] > mp[x * 2]) return {};
            for(int i = 0; i < mp[x]; i++, mp[x*2]--)
                ans.push_back(x);
        }

        return ans;
        
        
        
        return ans;
    }
};