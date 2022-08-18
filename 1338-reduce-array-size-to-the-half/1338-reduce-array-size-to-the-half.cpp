class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i : arr)
            mp[i]++;
        
        vector<int> freq;
        for(auto [k,v]: mp)
            freq.push_back(v);
        
        sort(freq.begin(), freq.end());
        
        int n = arr.size(), tar = arr.size() / 2, ans = 0;

        for(auto it = freq.rbegin(); it != freq.rend() && n > tar; it++){
            int val = *it;
            n -= val;
            ans++;
        }

    

        // priority_queue<int, vector<int>> pq;
        // for(auto [k,v] : mp)
        //     pq.push(v);
        

        
//         while(n > tar){
//             int tmp = pq.top();
//             pq.pop();
//             n-= tmp;
//             ans++;
//         }
        return ans;
    }
};