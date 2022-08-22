class Solution {
public:
    vector<int> movesToStamp(string s, string t) {
        if(s == t) return {0};
        int n = s.size(), m = t.size() - n + 1;
        
        vector<int> ans;

        bool tdiff = true, sdiff;

        int i, j;
        while(tdiff){
            for( i = 0, tdiff = false; i < m; i++){
                for( j = 0, sdiff = false; j < n; j++)
                    if(t[i+j] != '*' && t[i+j] != s[j]) break;
                    else if(t[i+j] != '*') sdiff = true;
                
                if( j == n && sdiff){
                    for(j = i, tdiff = true; j < n + i; j++)
                        t[j] = '*';
                    ans.push_back(i);
                }
            }
        }

        for(char c: t) if(c != '*') return {};
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};