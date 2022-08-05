class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> mp;
    map<int, int> times;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
        times[mp[tokenId]]++;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) == mp.end()) return;
        if(currentTime >= mp[tokenId]) return;
        int old_exp = mp[tokenId];
        int new_exp = currentTime + ttl;
        mp[tokenId] =  new_exp;
        times[old_exp]--;
        times[new_exp]++;
    }
    
    int countUnexpiredTokens(int currentTime) {
       auto it = times.upper_bound(currentTime);
       int ans = 0;
        // cout <<"At " <<currentTime << endl;
       while(it != times.end()){
           ans += it -> second;
           // cout << it -> first << " -> " << it -> second << endl;
           advance(it, 1);
       }
        cout << ans << endl;
        // cout << "__________________" << endl;
       return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */