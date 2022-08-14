class Solution {
public:
    int maxProfit(vector<int>& p) {
        bool cool_down = 0;
        int n = p.size();
      
        vector<vector<int>> curr(2, vector<int>(2, 0)), next(2, vector<int>(2, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cool_down = 0; cool_down <= 1; cool_down++){
                    if(buy){
                        int b = -p[idx] + next[0][0]; 
                        int nb = 0 + next[1][0];

                        if(cool_down) curr[buy][cool_down] = nb;
                        else curr[buy][cool_down] = max(b, nb);
                    }
                    else{
                        int s = p[idx] + next[1][1];
                        int ns = 0 + next[0][0];
                        curr[buy][cool_down] = max(s, ns);
                    }
                }
            }
            next = curr;
        }
        return curr[1][0];
    }
};