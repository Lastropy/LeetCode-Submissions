class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int p = 0, i;
        
        for(i = 1; i <= n && p < target.size(); i++){
            ans.push_back("Push");
            if(target[p] > i)
                ans.push_back("Pop");
            p += (target[p] == i);
        }
        return ans;
    }
};