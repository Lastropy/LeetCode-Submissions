class Solution {
public:
     using pi = pair<int, int>;
     vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>v;
        int n=nums.size();
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<=n-k;i++) pq.push({nums[i],i});
        auto t=pq.top();
        pq.pop();
        v.push_back(t.first);
        int minIDX=t.second;
        for(int i=n-k+1;i<n;i++){
            pq.push({nums[i],i});
            t=pq.top();
            while(t.second<minIDX){
              pq.pop();
              t=pq.top();
            }
            pq.pop();
            v.push_back(t.first);
            minIDX=t.second;
        }
        return v;
    }
};