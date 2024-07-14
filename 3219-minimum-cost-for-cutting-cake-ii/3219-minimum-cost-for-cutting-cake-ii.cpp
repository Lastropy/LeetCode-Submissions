class Solution {
public:
     long long calc(vector<int>& h, vector<int>& v, int &m, int &n){
        int i = 0, j = 0;
        long long ans = 0;
        int hp = 1, vp = 1;
        while(i < (m - 1) && j < (n - 1)){
            if(h[i] > v[j]){
                ans += (h[i] * vp * 1LL);
                hp++;
                i++;
            } else {
                ans += (v[j] * hp * 1LL);
                vp++;
                j++;
            }
        }
        
        
        while(i < (m - 1)){
            ans += (h[i] * vp * 1LL);
            i++;
        }
        
        while(j < (n - 1)){
            ans += (v[j] * hp * 1LL);
            j++;
        }
        return ans;
    }
    
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        reverse(h.begin(), h.end());        
        reverse(v.begin(), v.end());
        return calc(h, v, m, n);
    }
};