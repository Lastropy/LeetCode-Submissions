class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(begin(piles), end(piles));
        int ans = accumulate(begin(piles), end(piles), 0);
        
        while(k--)
        {
            int tmp = pq.top(); pq.pop();
            ans -= (tmp/2);
            pq.push(tmp - (tmp/2));
        }
        
        return ans;
    }
};