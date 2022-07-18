class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>({1}));
        if(n == 1)
            return ans;
        for(int i  = 1; i < n; i++){
            vector<int> temp;
            for(int j = 0; j <= i; j++){
                int val = 0;
                if(j > 0) val += ans[i-1][j-1];
                if(j <= i-1) val += ans[i-1][j];
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;  
    }
};