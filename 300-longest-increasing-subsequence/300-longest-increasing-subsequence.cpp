class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n  = a.size();
        vector<int> curr(n+1, 0), next(n+1 , 0);

        for(int idx = n-1; idx >= 0; idx--){

            for(int prev = idx -1; prev >= -1; prev--){

                int len = 0 + next[prev+1];    // not pick

                if(prev == -1 || a[idx] > a[prev])
                    len = max(len , 1 + next[idx+1]); // pick

                curr[prev + 1] = len;

            }
            next = curr;
        }

        return curr[0];
    }
};