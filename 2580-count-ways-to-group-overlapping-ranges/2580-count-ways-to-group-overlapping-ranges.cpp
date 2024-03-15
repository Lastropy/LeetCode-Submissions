class Solution {
public:
    int mod = 1e9 + 7;
    int permut(int n){
        int res = 1;
        for(int i = 0; i < n; i++){
            res = (res * 2) % mod;
        }
        return res;
    }
    int countWays(vector<vector<int>>& a) {
        map<int, int> mp;
        for(auto v: a){
            mp[v[0]]++;
            mp[v[1]]--;
        }
        
        int grps = 1, curr = 0;
        for(auto [k,v]: mp){
            curr += v;
            if(curr == 0) grps++;
        }
        return permut(grps - 1);
    }
};