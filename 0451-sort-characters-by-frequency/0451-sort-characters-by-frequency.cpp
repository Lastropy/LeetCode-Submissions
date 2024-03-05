class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        vector<string> freq(s.size() + 1);
        for(auto [ch, f]: mp)
            freq[f] += string(f, ch);
        string ans = "";
        for(int i = freq.size() - 1; i > 0; i--){
            if(freq[i].size())
                ans += freq[i];
        }
        return ans;
    }
};