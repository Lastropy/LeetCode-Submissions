class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int st = arr[i][0];
            int en = arr[i][1];
            while(i < n - 1 && en >= arr[i+1][0])
                en = max(arr[++i][1], en);
            ans.push_back({st, en});
        }
        return ans;
    }
};