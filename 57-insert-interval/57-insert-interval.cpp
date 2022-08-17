class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        int idx = 0;
        int n = in.size();
        vector<vector<int>> res;
        while(idx < n && in[idx][1] < ni[0])
            res.push_back(in[idx++]);
        int mx = ni[1], mn = ni[0];
        while(idx < n && in[idx][0] <= ni[1])
        {
            mn = min(in[idx][0] , mn);
            mx = max(in[idx][1], mx);
            idx++;
        }
        res.push_back(vector<int>({mn, mx}));
        while(idx < n)
            res.push_back(in[idx++]);
        return res;
    }
};