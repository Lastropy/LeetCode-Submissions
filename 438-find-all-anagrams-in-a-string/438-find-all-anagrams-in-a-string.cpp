class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int i, j;
        int n = s.size();
        map<char,int> mp;
        for(char c: p)
            mp[c]++;
        int uniq = mp.size();
        vector<int> ans;
        for(i = 0, j = 0; j < n; j++ ){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    uniq--;
            }
            if(j - i + 1 == k){
                if(uniq == 0)
                    ans.push_back(i);
                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        uniq++;
                }
                i++;
            }
        }
        return ans;
    }
};