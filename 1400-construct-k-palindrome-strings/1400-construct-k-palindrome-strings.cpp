class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n) return false;
        if(k == n) return true;
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        
        int buckets = mp.size();
        if(buckets <= k) return true;
        int eveners = 0, odders = 0;
        for(auto [k, v]: mp){
            if(v % 2 == 0) eveners++;
            else odders++;
        }
        if(eveners == odders) return true;
        return k >= odders;       
        
        /*
            abcd = {
                a: 1
                b: 1
                c: 1
                d: 1
            }
            x1, x2, x3
            
            abbd = {
                a: 1
                b: 2
                d: 1
            }
            x1, 2,
            e  = 1
            o  = 2
        
        
        
        */
    }
};