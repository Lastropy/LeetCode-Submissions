class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for(int i : arr)
            mp[i]++;
        int n = arr.size();
        int tar = arr.size() / 2;
        priority_queue<int, vector<int>> pq;
        for(auto [k,v] : mp)
            pq.push(v);
        int ans = 0;
        while(n > tar){
            int tmp = pq.top();
            pq.pop();
            n-= tmp;
            ans++;
        }
        return ans;
    }
};