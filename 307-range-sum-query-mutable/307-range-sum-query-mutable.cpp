class NumArray {
public:
    vector<int> a;
    int sum;
    NumArray(vector<int>& nums) {
        sum = 0;
        for(int i= 0; i < nums.size(); i++){
            sum += nums[i];
            a.push_back(nums[i]);
        }
    }
    
    void update(int index, int val) {
        int old = a[index];
        a[index] = val;
        sum += (val - old);
    }
    
    int sumRange(int left, int right) {
        int ans  = 0;
        if(right  - left  < (a.size() / 2))
            ans = accumulate(a.begin() + left, a.begin() + right + 1, 0);
        else
            ans = sum - accumulate(a.begin(), a.begin() + left, 0) - accumulate(a.begin() + right + 1, a.end() , 0);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */