class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](vector<int> &a, vector<int> &b){
           return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; 
        });
        
        
        int ans = 0;
        int mx = INT_MIN;
        for(int i = properties.size() - 1; i >= 0; i--){
            if(properties[i][1] < mx)
                ans++;
            mx = max(mx, properties[i][1]);
        }
        
        return ans;
    }
};