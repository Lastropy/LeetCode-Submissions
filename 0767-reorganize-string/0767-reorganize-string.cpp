class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(char c: s){
            mp[c]++;
            if(mp[c] > ceil((double)n/2.0))
                return "";
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto [k,v]: mp){
            pq.push({v, k});
        }
        int pos = 0;
        while(!pq.empty()){
            char c; int f;
            tie(f, c) = pq.top();
            pq.pop();
            while(f--){
                s[pos] = c;
                pos = (pos + 2);
                if(pos >= n) pos = 1;
            }
        }
        return s;
    }
};