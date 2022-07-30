class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> free;
        for(int i =0; i< times.size(); i++)
            free.insert(i);
        vector<vector< int>> log;
        for(int i = 0; i < times.size() ; i++){
            auto t= times[i];
            log.push_back(vector<int>({t[0], +1, i}));
            log.push_back(vector<int>({t[1], -1, i}));
        }
        map<int, int> mp;
        sort(log.begin(), log.end());
        for(auto l: log){
            auto it = free.begin();
            if(l[1] == 1){
                mp[l[2]] = *it;
                free.erase(it);
            }
            else{
                free.insert(mp[l[2]]);
                mp.erase(l[2]);
            }
            if(l[2] == targetFriend){
                return mp[l[2]];
            }
        }
        return 0;
    }
};