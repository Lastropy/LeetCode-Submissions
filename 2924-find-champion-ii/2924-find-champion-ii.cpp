class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for(auto e: edges){
            indeg[e[1]]++;
        }
        
        int candidate = -1;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                if(candidate == -1) candidate = i;
                else return -1;
            }
        }
        return candidate;
    }
};