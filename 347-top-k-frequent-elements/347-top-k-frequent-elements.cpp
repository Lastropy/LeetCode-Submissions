class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> pi;
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        priority_queue<pi, vector<pi> , greater<pi>> pq;
        for(auto [key,v]: mp)
        {
            pq.push({v,key});
            if(pq.size() > k)
                pq.pop();
        }
        vector< int > ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};