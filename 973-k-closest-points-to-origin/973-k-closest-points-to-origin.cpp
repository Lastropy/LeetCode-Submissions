class Solution {
public:
    double dist(int x, int y){
        double ans = pow(x,2) + pow(y,2);
        ans = sqrt(ans);
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<double, pair<int,int>> pdpi;
        priority_queue<pdpi> pq;
        for(auto pt: points){
            pq.push({dist(pt[0],pt[1]),{pt[0],pt[1]}});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto cord = pq.top().second;
            int x = cord.first;
            int y = cord.second;
            ans.push_back(vector<int>({x,y}));
            pq.pop();
        }
        return ans;
    }
};