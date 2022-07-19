class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // Min - heap
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i  = 0; i < n; i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        int ans = pq.top();
        return ans;
    }
};