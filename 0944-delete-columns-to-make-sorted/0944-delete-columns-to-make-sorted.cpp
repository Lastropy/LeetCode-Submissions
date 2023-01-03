class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if(strs.size() == 1) return 0;
        
        int n = strs.size();
        int m = strs[0].size();
        unordered_set<int> ignore;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                    // cout << i << ' ' << j << endl;
                if(ignore.count(j)) continue;
                if(strs[i][j] > strs[i+1][j]){
                    ignore.insert(j);
                }
            }
        }
        return ignore.size();
    }
};