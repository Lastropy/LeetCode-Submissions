class Solution {
public:
     int up(vector<int> &a, int st , int en , int &tar){
        if(st > en) return -1;
        int mid = st + (en - st) /2;
        if(a[mid] == tar){
            int upper = up(a, mid + 1, en, tar);
            if(upper == -1) return mid;
            return upper;
        }
        else if(a[mid] > tar)
            return up(a, st, mid - 1, tar);
        return up(a, mid + 1, en, tar);
    }
    int low(vector<int> &a, int st , int en , int &tar){
        if(st > en) return -1;
        int mid = st + (en - st) /2;
        if(a[mid] == tar){
            int lower = low(a, st, mid - 1, tar);
            if(lower == -1) return mid;
            return lower;
        }
        else if(a[mid] > tar)
            return low(a, st, mid - 1, tar);
        return low(a, mid + 1, en, tar);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = low(nums, 0 , n-1, target);
        if(lb == -1)
            return vector<int> ({-1, -1});
        int ub = up(nums, 0 , n-1, target);
        return vector<int>({lb, ub});
    }
};