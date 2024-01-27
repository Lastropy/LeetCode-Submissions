class Solution {
public:
    int reachable(vector<int> &a, int sp, double tar){
        double curr = 0;
        for(int i = 0; i < a.size(); i++){
            double curr_time = (((double)a[i])/sp);
            curr += (i < a.size() - 1 ? ceil(curr_time): curr_time);
        }
        return (curr <= tar);
    }
    int minSpeedOnTime(vector<int>& a, double t) {
        long long s= 1, e = INT_MAX;
        int ans = -1;
        while(s <= e){
            long long m = s + (e - s)/2;
            if(reachable(a,m,t)){
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
};