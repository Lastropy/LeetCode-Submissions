class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        deque<int> d;
        vector<int> ans;
        int i = 0, j = 0;
        for(i = 0, j = 0; j < n; j++){
            while(!d.empty() && a[j] > d.back())
                d.pop_back();
            d.push_back(a[j]);
            if(j - i + 1 == k){
                ans.push_back(d.front());
                if(a[i++] == d.front())
                    d.pop_front();
            }
        }
        return ans;
        
    }
};