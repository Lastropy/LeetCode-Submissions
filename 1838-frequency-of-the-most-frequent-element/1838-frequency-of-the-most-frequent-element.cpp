class Solution {
public:
    int maxFrequency(vector<int>& a, int k) {
        int i = 0, j = 0;
        sort(a.begin(), a.end());
        int n = a.size();
        long tot = 0;
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(a[i-1] != a[i])
                break;
            ans++;
        }
        int winSize = 1;
        for(i = 0, j = 0; j < n ; j++){
            tot += a[j];
            winSize = j- i + 1;
            if(tot + 1LL * k >= 1LL * a[j] * winSize)
                ans = max(ans, winSize);
            else{
                while(i < n && tot + k < 1LL * a[j] * winSize){
                    tot -= a[i];
                    i++;
                    winSize = j - i + 1;
                }
            }
        }
        return ans;
    }
};