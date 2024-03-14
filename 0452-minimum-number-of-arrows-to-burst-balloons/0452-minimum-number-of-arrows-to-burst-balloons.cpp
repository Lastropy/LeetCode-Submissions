class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        
        int ans = 0, n = a.size();
        for(int i = n - 1; i >= 0;){
            int shotLocation = a[i][0];
            ans++;
            while(i >= 0 && a[i][0] <= shotLocation && a[i][1] >= shotLocation)
                i--;
        }
        return ans;
    }
};