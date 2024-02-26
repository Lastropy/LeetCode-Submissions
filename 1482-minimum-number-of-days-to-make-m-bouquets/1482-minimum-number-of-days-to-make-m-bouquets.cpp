class Solution {
public:
    bool canHarvest(int mid, vector<int>& g, int m, int k){
        int ans = 0, curr = 0;
        for(int i = 0; i < g.size(); i++){
            if(g[i] <= mid){
                curr++;
            } else {
                curr = 0;
            }
            if(curr == k) {
                curr = 0;
                ans++;
            }
        }
        return (ans >= m);
    }
    
    int minDays(vector<int>& g, int m, int k) {
        int n = g.size();
        if(1LL * m * k > n) return -1;
        int s = *min_element(g.begin(), g.end());
        int e = *max_element(g.begin(), g.end());
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(canHarvest(mid, g, m, k)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};