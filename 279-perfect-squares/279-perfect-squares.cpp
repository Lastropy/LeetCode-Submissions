class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        
        vector<int> cntSq(n + 1, INT_MAX);
        cntSq[0] = 0;
        cntSq[1] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j* j <= i; j++){
                cntSq[i] = min(cntSq[i], cntSq[i - j*j]+ 1);
            }   
        }
        
        return cntSq[n];
    }
};