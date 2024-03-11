class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int ans = 1;
        vector<int> f(26, 0);
        for(int i =0;i < n; i++){
            if(f[s[i] - 'a'] == 1){
                ans++;
                f = vector<int>(26,0);
            }
             f[s[i] - 'a'] = 1;
        }
        return ans;
    }
};