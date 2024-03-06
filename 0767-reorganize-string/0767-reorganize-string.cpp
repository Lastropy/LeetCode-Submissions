class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(char c: s){
            mp[c]++;
            if(mp[c] > ceil((double)n/2.0))
                return "";
        }
        
        vector<string> buckets(n + 1);
        for(auto [k,v]: mp){
            buckets[v] += string(1,k);
        }
        
        int pos = 0;
        for(int i = ceil((double)n/2.0); i >= 0; i--){
            for(int j = 0; j < buckets[i].size(); j++){
                int f = i;
                while(f--){
                    s[pos] = buckets[i][j];
                    pos = (pos + 2);
                    if(pos >= n) pos = 1;
                }
            }
        }
        return s;
    }
};