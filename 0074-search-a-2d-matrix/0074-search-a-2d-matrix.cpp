class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int n  = mat.size(), m = mat[0].size();
        int rNum = INT_MAX, low = 0, high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mat[mid][0] <= tar){
                rNum = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        if(rNum == INT_MAX) return false;
        
        low = 0, high = m - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mat[rNum][mid] < tar) low = mid + 1;
            else if(mat[rNum][mid] > tar) high = mid - 1;
            else return true;
        }
        return false;
    }
};