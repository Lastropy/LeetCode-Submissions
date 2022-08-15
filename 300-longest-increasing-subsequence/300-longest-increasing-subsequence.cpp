class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n  = a.size();
        vector<int> ans;
        for(int i = 0; i < a.size(); i++){
            if(ans.empty() || ans.back() < a[i])
                ans.push_back(a[i]);
            else{
                int lb = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[lb] = a[i];
            }
        }
        return ans.size();
    }
};