class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> minf, freq;
        for(int i = 0; i < 26; i++)
            minf['a' + i] = INT_MAX;
        
        for(auto word : words){
            for(char c : word)
                freq[c]++;
            for(int i = 0; i < 26; i++)
               minf['a' + i] = min(minf['a' + i], freq['a' + i]);
            freq.clear();
        }
        
        vector<string> ans;
        for(auto [k,v]: minf){
            for(int i = 0; i < v; i++)
                ans.push_back(string(1,k));
        }
        return ans;
    }
};