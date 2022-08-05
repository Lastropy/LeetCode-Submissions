class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> mp;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) == mp.end()) return;
        if(currentTime >= mp[tokenId]) return;
        mp[tokenId] = currentTime + ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for(auto [k,v ] : mp){
            if(v > currentTime)
                ans++;
        }
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