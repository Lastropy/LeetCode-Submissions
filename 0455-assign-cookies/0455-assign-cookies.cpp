class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, n = g.size(), m = s.size();
        for(int i = 0, j = 0; i < n; i++){
            while(j < m && g[i] > s[j]) j++; 
            if(j < m) ans++;
            j++;
        }
        return ans;
    }
};