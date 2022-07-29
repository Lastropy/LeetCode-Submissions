class Solution {
public:
    bool check(string s, string p){
        if(s.size() != p.size()) return false;
        map<char, char> mp;
        vector<int> mapped(26, 0);
        string res = "";
        for(int i  = 0; i < s.size(); i++){
            char so = s[i];
            char tar = p[i];
            if(mp.count(so))
                res += mp[so];
            else{
                if(mapped[tar - 'a'])
                    return false;
                res += tar;
                mapped[tar-'a'] = 1;
                mp[so] = tar;
            }
        }
        // cout << s << endl;
        //    for(auto [k,v]: mp)
        //         cout << k << '-' << v << endl;
        // cout << "________________________" << endl;
        return res == p;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string s: words){
            if(check(s, pattern))
                ans.push_back(s);             
        }
        return ans;
    }
};