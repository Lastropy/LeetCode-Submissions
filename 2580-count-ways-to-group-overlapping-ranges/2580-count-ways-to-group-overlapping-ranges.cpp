class Solution {
public:
    int mod = 1e9 + 7;
    int permut(int n){
        int res = 1;
        for(int i = 0; i < n; i++){
            res = (res * 2) % mod;
        }
        return res;
    }
    int countWays(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [&](const vector<int> &p, const vector<int> &q){
            return p[0] < q[0];
        });
        
        int grps = 1, curr = 0, curr_max = a[0][1];
        for(int i = 1; i < a.size(); i++){
            if(a[i][0] > curr_max){
                grps++;
                curr_max = a[i][1];
            }
            curr_max = max(curr_max, a[i][1]);
        }
        return permut(grps);
    }
};