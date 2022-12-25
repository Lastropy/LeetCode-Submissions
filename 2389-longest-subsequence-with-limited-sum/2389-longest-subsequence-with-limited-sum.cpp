class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int csum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i];
            nums[i] += csum;
            csum += tmp;
        }
        for(int i = 0; i < queries.size(); i++)
        {
            auto pos = upper_bound(begin(nums), end(nums), queries[i])- begin(nums);
            queries[i] = pos;
        }
        return queries;
    }
};