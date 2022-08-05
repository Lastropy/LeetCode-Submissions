class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> mp;
    // map<int, int> times;
    multiset<int> times;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
        // times[mp[tokenId]]++;
        times.insert(mp[tokenId]);
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) == mp.end()) return;
        if(currentTime >= mp[tokenId]) return;
        int old_exp = mp[tokenId];
        int new_exp = currentTime + ttl;
        mp[tokenId] =  new_exp;
        // for(int i: times){
        //     cout << i << ",";
        // }
        // cout << endl;
        times.erase(times.find(old_exp));
        times.insert(mp[tokenId]);
        // for(int i: times){
        //     cout << i << ",";
        // }
        // cout << endl;
        // times[old_exp]--;
        // times[new_exp]++;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
//        auto it = times.upper_bound(currentTime);
       
//        while(it != times.end()){
//            ans += it -> second;
//            advance(it, 1);
//        }
        auto it = times.upper_bound(currentTime);
        ans = times.size() - distance(times.begin(), it);
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