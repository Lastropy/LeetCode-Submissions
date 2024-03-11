class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] - '0' > k) return -1;
        }
        
        int ans = 1;
        long long part = 0;
        for(int i = 0; i < n; i++){
            int dig = s[i] -'0';
            if(part * 10 + dig <= k){
                part = part * 10 + dig;
            } else {
                ans++;
                part = dig;
            }
        }
        return ans;
    }
};