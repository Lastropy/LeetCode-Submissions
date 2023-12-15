class Solution {
public:
    int balancedString(string s) {
        //step - 1
        int n = s.size();
        int des = n / 4;
        unordered_map<char, int> mp;
        
        for(char c: s) mp[c]++;
        
        // step - 2
        for(auto [k,v]: mp){
            mp[k] = max(0,v- des);
        }
        
        if(mp['Q'] == 0 && mp['R'] == 0 && mp['W'] == 0 && mp['E'] == 0)
            return 0;
        
        /*
            QRQEQWRR
            Q -> 1
            R -> 1
            E -> 0
            W -> 0
        */
        
        // step - 3
        int ans = n;
        for(int i =0, j= 0; j< n; j++){
            if(mp.count(s[j]))
                mp[s[j]]--;
            while(mp['Q'] <= 0 && mp['R'] <= 0 && mp['W'] <= 0 && mp['E'] <= 0){
                if(mp.count(s[i])){
                    mp[s[i]]++;
                }
                ans = min(ans, j - i + 1);
                i++;
            }
        }
        return ans;
    }
};