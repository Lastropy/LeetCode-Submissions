class Solution {
public:
    int titleToNumber(string s) {
        long long ans = 0;
        long long base = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            ans += (base) * (s[i] - 'A' + 1);
            base *= 26;
        }
        return ans;
    }
};