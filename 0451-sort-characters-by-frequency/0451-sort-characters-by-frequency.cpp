class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        vector<vector<char>> freq(s.size() + 1);
        for(auto [ch, f]: mp){
            freq[f].push_back(ch);
        }
        
        string ans = "";
        for(int i = freq.size() - 1; i > 0; i--){
            auto v = freq[i];
            for(char ch: v){
                ans += string(i, ch);
            }
        }
        return ans;
    }
};