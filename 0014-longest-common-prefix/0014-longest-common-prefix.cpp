class Solution {
public:
    string longestCommonPrefix(vector<string>& mat) {
        int n = mat.size();
        if(n == 0) return "";
        if(n == 1) return mat[0];
        string ans = mat[0];
        for(int i = 1; i < n; i++){
            int j = 0;
            while(j < mat[i].size() && j < ans.size()){
                if(mat[i][j] != ans[j]) break;
                j++;
            }
            ans = ans.substr(0, j);
        }
        return ans;
    }
};