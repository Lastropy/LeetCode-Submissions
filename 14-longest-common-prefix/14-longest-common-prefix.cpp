class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        string f = strs[0];
        string l = strs[strs.size() - 1];
        for(int j = 0;  j < min(f.size(), l.size()); j++){
            if(f[j] != l[j])
                break;
            ans += f[j];
            
        }
        return ans;
    }
};