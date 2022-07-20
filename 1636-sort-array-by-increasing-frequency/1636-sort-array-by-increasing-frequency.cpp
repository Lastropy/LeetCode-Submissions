class Solution {
public:
    bool comp(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        typedef pair<int, int> pi;
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        priority_queue<pi> pq;
        for(auto [k,v ]: mp){
            pq.push({v,100 - k});
        }
        vector<int> ans;
        while(!pq.empty()){
            int num = 100-  pq.top().second;
            int f = pq.top().first;
            pq.pop();
            while(f--)
                ans.push_back(num);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};