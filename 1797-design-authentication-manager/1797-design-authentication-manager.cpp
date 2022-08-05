class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> mp;
    multiset<int> times;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
        times.insert(mp[tokenId]);
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) == mp.end()) return;
        if(currentTime >= mp[tokenId]) return;
        times.erase(times.find(mp[tokenId]));
        this -> generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        return times.size() - distance(times.begin(), times.upper_bound(currentTime));
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */