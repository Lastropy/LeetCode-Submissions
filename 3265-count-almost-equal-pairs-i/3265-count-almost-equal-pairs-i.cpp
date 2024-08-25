class Solution {
public:
    bool eq(int i, int j){
        if(i == j) return true;
        string s = to_string(i), t = to_string(j);
        if(s.size() > t.size()) swap(s, t);
        if(s.size() != t.size()) {
            int nz = t.size() - s.size();
            s = string(nz, '0')  + s;
        }
        vector<int> pos;
        for(int idx = 0; idx < s.size(); idx++){
            if(s[idx] != t[idx]){
                pos.push_back(idx);
                if(pos.size() > 2) return false;
            }
        }
        if(pos.size() == 0) return true;
        if(pos.size() == 2){
            swap(s[pos[0]], s[pos[1]]);
            return (s == t);
        }
        return false;
    }
    
    int countPairs(vector<int>& a) {
        int ans = 0, n = a.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(eq(a[i], a[j])) {
                    ans++;
                    // cout << a[i] << " " << a[j] << " => " << ans << endl;
                }
            }
        }
        return ans;
    }
};