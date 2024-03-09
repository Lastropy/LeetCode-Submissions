class Solution {
public:
    using vi = vector<int>;
    vector<int> smallestRange(vector<vector<int>>& a) {
        int k = a.size(), mxEle = INT_MIN;
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        for(int i = 0; i < k; i++){
            pq.push({a[i][0], i, 0});
            mxEle = max(mxEle, a[i][0]);
        }
        vector<int> ans({pq.top()[0], mxEle});
        while(pq.size() == k){
            int r = pq.top()[1], c = pq.top()[2]; pq.pop();
            if(c + 1 < a[r].size()) {
                pq.push({a[r][c + 1], r, c + 1}); 
                mxEle = max(a[r][c + 1], mxEle);
                if(ans[1] - ans[0] > mxEle - pq.top()[0])
                    ans = {pq.top()[0], mxEle};
            }
        }
        return ans;
    }
};