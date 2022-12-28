class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;
        for(int i: piles){
            if(i) pq.push(i);
            ans += i;
        }
        
        while(!pq.empty() && k--)
        {
            int tmp = pq.top(); pq.pop();
            // cout << ans << endl;
            ans -= (tmp/2);
            tmp = tmp % 2 ? (tmp/2) + 1 : (tmp / 2);
            if(tmp) pq.push(tmp);
        }
        
        return ans;
    }
};