class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& n, vector<int>& p) {
        long long ans = 0;
        vector<long long> next(26, 0), prev(26, 0);
        next[0] = n[0];
        for(int i = 1; i < 26; i++){
            next[i] = next[i - 1] + n[i];
        }
        prev[25] = p[25];
        for(int i = 24; i >= 0; i--){
            prev[i] = prev[i + 1] + p[i];
        }
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[i]) continue;
            int c1 = s[i] - 'a', c2 = t[i] - 'a';
            long long nxpr1 = c1 ? next[c1 - 1] : 0;
            long long nxpr2 = c2 ? next[c2 - 1] : 0;
            long long prnx1 = c1 < 25 ? prev[c1 + 1]: 0;
            long long prnx2 = c2 < 25 ? prev[c2 + 1]: 0;
            long long pos1, pos2;
            if(s[i] < t[i]) {
                pos1 = (prev[0] - prnx1) + (prnx2);
                pos2 = nxpr2 - nxpr1;
            } else {
                pos1 = nxpr2 + (next[25] - nxpr1);
                pos2 = prnx2 - prnx1;
            }
            ans += min(pos1, pos2);
        }
        return ans;
    }
};