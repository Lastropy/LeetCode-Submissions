class Solution {
public:
    int max_with_row(vector<int> &a, int k){
        set<int> seen;

        int ps = 0, ans = INT_MIN;
        seen.insert(0);

        for(int ele: a){
            ps += ele;
            
            auto pos = seen.lower_bound(ps - k);
            if(pos != seen.end())
                ans = max(ans, ps - (*pos));
            if(ans == k) return ans;
            seen.insert(ps);
        }

        return ans;
    }

    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int ans = INT_MIN;

        for(int i = 0; i < m; i++)
        {
            vector<int> ps(n, 0);
            for(int j = i; j < m; j++)
            {
                for(int k = 0; k < n; k++)
                    ps[k] += mat[j][k]; 
                
                ans = max(ans, max_with_row(ps, k));
                if(ans == k) return ans;
            }    
        }

        return ans;        
    }
};