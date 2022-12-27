class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int adr) {
        int n = rocks.size(), ans = 0;
        
        for(int i = 0;i < n; i++)
            capacity[i] -= rocks[i];
        
        sort(begin(capacity), end(capacity));
        
        for(int i: capacity){
            if(adr  < i) break;
            adr -= i;
            ans++;
        }
        return ans;
    }
};