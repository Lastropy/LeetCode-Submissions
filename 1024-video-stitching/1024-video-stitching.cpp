class Solution {
public:
    int videoStitching(vector<vector<int>>& a, int time) {
        sort(a.begin(), a.end(), [&](const vector<int> &a, const vector<int> &b){
           if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int ans = 0, n = a.size(), curr_max_end = -1;
        vector<int> prev = {0, 0};
        for(int i = 0; i < n && curr_max_end < time;){
            vector<int> candidate = {-1, -1};
            curr_max_end = prev[1];
            while(i < n && curr_max_end < time){
                // cout << "PREV: " << prev[0] << " -> " << prev[1] << endl;
                // cout << "CURR: " << a[i][0] << " -> " << a[i][1] << endl;
                // cout << "CURR MAX END: " << curr_max_end << endl;
                if(a[i][0] <= prev[1] && a[i][1] <= curr_max_end) {
                    // cout << "CASE 1" << endl;
                    // cout << endl;
                    i++;
                }
                else if(a[i][0] <= prev[1] && a[i][1] > curr_max_end) {
                    // cout << "CASE 2" << endl;
                    // cout << endl;
                    candidate = a[i];
                    curr_max_end = a[i][1];
                    i++;
                }
                else {
                    // cout << "CASE 3" << endl;
                    // cout << endl;
                    break;
                }
            }
            ans++;
            // cout<< "ANS : " << ans << endl;
            // cout << "CANDIDATE: " << candidate[0] << " -> " << candidate[1] << endl;
            // cout<< endl;
            if(curr_max_end >= time) return ans;
            if(candidate[0] == -1) return -1;
            prev = candidate;
        }
        return (curr_max_end >= time? ans: -1);
        
    }
};