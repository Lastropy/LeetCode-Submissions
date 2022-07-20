class Solution {
public:
    long dist(int x, int y){
        long ans = pow(x,2) + pow(y,2);
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<long, vector<int>> pdpi;
        priority_queue<pdpi> pq;
        for(auto pt: points){
            pq.push({dist(pt[0],pt[1]),pt});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto cord = pq.top().second;
            ans.push_back(cord);
            pq.pop();
        }
        return ans;
    }
};