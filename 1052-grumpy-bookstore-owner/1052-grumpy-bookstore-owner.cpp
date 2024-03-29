class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        // vector<int> ps(g.size());
        // int curr = 0;
        // for(int i =0; i < g.size(); i++){
        //     c[i] *= (g[i] == 0 ? 1: -1);
        //     curr += c[i] > 0 ? c[i] : 0;
        //     ps[i] = curr;
        // }
        // vector<int> ss(g.size());
        // curr = 0;
        // for(int i = g.size() - 1; i >= 0;i--){
        //     curr += c[i] > 0 ? c[i] : 0;
        //     ss[i] = curr;
        // }
        // int ans = INT_MIN;
        // int sum = 0;
        // for(int i = 0, j = 0; j < g.size(); j++){
        //     sum += abs(c[j]);
        //     if(j - i + 1 == k){
        //         ans = max(ans, sum  + (i > 0 ? ps[i-1]: 0) + (j < g.size() - 1 ? ss[j+1] : 0));
        //         sum -= abs(c[i]);
        //         i++;
        //     } 
        // }
        // return max(ans, sum);
        
        int normal_satisfaction = 0;
        int max_satisfaction_if_behaving = INT_MIN;
        int satisfaction_if_behaving = 0;
        for(int i = 0, j = 0; j < c.size(); j++){
            normal_satisfaction  += (!g[j]) * c[j];
            satisfaction_if_behaving  += g[j] * c[j];
            max_satisfaction_if_behaving = max(satisfaction_if_behaving, max_satisfaction_if_behaving);
            if(j - i + 1 == k)
            {
                satisfaction_if_behaving -= g[i] * c[i];
                i++;
            }
        }
        return normal_satisfaction + max_satisfaction_if_behaving;
    }
};