class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0)), next(2, vector<int>(k+1, 0));

        for(int idx = n-1; idx >= 0; idx--){

            for(int buy = 0; buy <= 1; buy++){

                for(int lim = 0; lim <= k; lim++){

                    if(lim == 0) 
                        curr[buy][lim] = 0;

                    else if(buy){
                        int b = -p[idx] + next[0][lim];

                        int nb = 0 + next[1][lim];

                        curr[buy][lim] = max(b, nb);   
                    }

                    else{
                        int s = p[idx] + next[1][lim-1];

                        int ns = 0 + next[0][lim];

                        curr[buy][lim] = max(s, ns);  
                    }

                }

            }

            next = curr;

        }
        return curr[1][k];
    }
};