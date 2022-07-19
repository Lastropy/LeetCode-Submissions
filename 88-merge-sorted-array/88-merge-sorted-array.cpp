class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        map<int, int> mp;
        for(int i = 0; i < m; i++){
            mp[a[i]]++;
        }
        
        for(int j = 0; j < n; j++){
            mp[b[j]]++;
        }
        int pos  = 0;
        for(auto [k,v]: mp){
            while(v){
                a[pos++] = k;
                v--;
            }
        }
        return;
    }
};