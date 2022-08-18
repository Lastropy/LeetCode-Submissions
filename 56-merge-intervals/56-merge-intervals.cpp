class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for(auto in: intervals){
            if(merged.empty() || merged.back()[1] < in[0])
                merged.push_back(in);
            else
                merged.back()[1] = max(merged.back()[1], in[1]);
        }
        return merged;
    }
};