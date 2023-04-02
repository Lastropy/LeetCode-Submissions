class Solution {
    #define ll long long
    public:
        int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
            priority_queue<ll> pq;
            ll n = r1.size(), ans = 0;
            for(int i =0; i < n; i++){
                ans += r2[i];
                pq.push({r1[i] -r2[i]});
            }

            while(k){
                ans += pq.top(), k--; 
                pq.pop();
            }
      
            return ans;
        }
};