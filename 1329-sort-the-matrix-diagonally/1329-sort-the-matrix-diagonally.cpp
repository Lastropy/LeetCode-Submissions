class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int r = m-1; r >= 0; r--){
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int i = r, j = 0; j < n && i < m; j++, i++){
                // cout << i << "," << j << endl;
                pq.push(mat[i][j]);
            }
            // cout << "______________" << endl;
            for(int i = r, j = 0; j < n && i < m; j++, i++){
                mat[i][j] = pq.top();
                pq.pop();
            }
    
        }

        for(int c = 1; c < n; c++){
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int i = 0, j = c; j < n && i < m; i++, j++){
                // cout << i << "," << j << endl;
                pq.push(mat[i][j]);
            }

            // cout << "______________" << endl;
            for(int i = 0, j = c; j < n && i < m; j++, i++){
                mat[i][j] = pq.top();
                pq.pop();
            }
        }
        
        return mat;
    }
    
};