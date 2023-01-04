class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i: tasks)
            mp[i]++;
      
        int r = 0;
        while(!mp.empty()){
            for(auto &[k,v]:mp)
            {
                if(v < 2) return -1;
                if(v >= 3 && (v-3 > 2 || v-3 == 0))  v -= 3;
                else v-= 2;
                if(v == 0) mp.erase(k);
                r++;
            }
        }
      
        return r;
    }
};