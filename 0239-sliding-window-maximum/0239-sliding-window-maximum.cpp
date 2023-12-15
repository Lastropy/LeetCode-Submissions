class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;
        int n = a.size();
        vector<int> ans;
        for(int i = 0, j = 0;  j < n; j++){
            while(dq.size() > 0 && dq.back() < a[j]){
                dq.pop_back();
            }
            dq.push_back(a[j]);
            
            if(j - i + 1 == k){
                ans.push_back(dq.front());
                if(dq.front() == a[i]) 
                    dq.pop_front();
                i++;
            }
        }
        return ans;
    }
};