class Solution {
public:
    void merge(vector<int> &arr, int st, int mid, int en){
        int left = st, right = mid + 1;
        vector<int> temp;
        while(left <= mid && right <= en){
            if(arr[left] > arr[right]){
                temp.push_back(arr[right]);
                right++;
            } else {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        } 
        while(right <= en){
            temp.push_back(arr[right++]);
        }
        for(int i = 0; i < temp.size(); i++)
            arr[i + st] = temp[i];
    }
    int count_pairs(vector<int> &arr, int st, int mid, int en){
        int right = mid + 1;
        int cnt = 0;
        for(int left = st; left <= mid; left++){
            while(right <= en && arr[left] > 1LL * 2 * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int merge_sort(vector<int> &arr ,int st, int en){
        int mid = st + (en - st)/2, curr_count = 0;
        if(st >= en) return curr_count;
        curr_count += merge_sort(arr, st, mid);
        curr_count += merge_sort(arr, mid + 1, en);
        curr_count += count_pairs(arr, st, mid, en);
        merge(arr, st, mid, en);
        return curr_count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(nums, 0 , n - 1);
    }
};