class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> boundary_freq;
        int n = wall.size();
        
        int last_boundary = accumulate(wall[0].begin(), wall[0].end(), 0);
        int ans = n;
        for(auto w: wall){
            int pref = 0;
            for(int i: w){
                pref += i;
                if(pref != last_boundary){
                    boundary_freq[pref]++;
                    ans = min(ans, (n - boundary_freq[pref]));
                }
            }
        }
        return ans;
    }
};