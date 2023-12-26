class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        int jumps = 1, maxR = a[0], steps = a[0];
        if(n <= 1) return 0;
        if(a[0] == 0) return -1;
        
        for(int i = 1; i < n; i++){
            if(i == n-1){
                return jumps;
            }
            
            maxR = max(maxR, i + a[i]);
            steps--;
            if(steps == 0){
                jumps++;
                if(i >= maxR){
                    return -1;
                }
                steps = maxR - i;
            }
        }
        return -1;        
    }
};