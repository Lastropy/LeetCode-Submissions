class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        int n = s.size(), ans = INT_MAX, des = n / 4;
        for(char c: s) mp[c]++;
        for(auto [k, v]: mp) mp[k] = max(0, v - des);
        if(mp['Q'] == 0 && mp['W'] == 0 && mp['E'] == 0 && mp['R'] == 0) return 0;
        for(int i = 0, j = 0; j < n; j++){
            mp[s[j]]--;
            while(i <= j && mp['Q'] <= 0 && mp['W'] <= 0 && mp['E'] <= 0 && mp['R'] <= 0){
                ans = min(ans, j - i + 1);
                mp[s[i]]++;
                i++;
            }
        }
        return ans;
        
    }
};