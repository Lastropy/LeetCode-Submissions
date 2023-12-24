class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hor, vector<int>& vert) {
        int mod = 1e9 + 7;
        hor.insert(hor.begin() + 0,1);
        hor.push_back(m);
        sort(hor.begin(), hor.end());
        vert.insert(vert.begin()+ 0, 1);
        vert.push_back(n);
        sort(vert.begin(), vert.end());
        long long ans = -1;
        unordered_map<long long, int> mp;
        for(int i = 0; i < hor.size(); i++){
            for(int j = i+1; j < hor.size(); j++){
                int diff1 = hor[j]- hor[i];
                mp[diff1]++;
            }
        }
        for(int k = 0; k < vert.size(); k++){
            for(int l = k+1; l < vert.size(); l++){
                int diff2 = vert[l] - vert[k];
                if(mp.count(diff2)){
                    ans = max(ans, 1LL * diff2 * diff2);
                } 
            }
        }
        return ans % mod;
    }
};