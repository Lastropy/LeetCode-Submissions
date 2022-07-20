class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int pos = -1, mn = INT_MAX;
        for(int i = 0; i < points.size(); i++){
            auto v = points[i];
            if(v[0] == x){
                if(abs(v[1]-y) < mn){
                    mn = abs(v[1]-y);
                    pos = i;
                }
            }
            else if(v[1] == y){
                if(abs(v[0]-x) < mn){
                    mn = abs(v[0]-x);
                    pos = i;
                }
            }
        }
        if(pos == -1) return -1;
        return pos;
    }
};