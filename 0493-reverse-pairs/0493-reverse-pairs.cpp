class Solution {
public:
    int cnt = 0;
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
    void count_pairs(vector<int> &arr, int st, int mid, int en){
        int right = mid + 1;
        for(int left = st; left <= mid; left++){
            while(right <= en && arr[left] > 1LL * 2 * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
    }
    void merge_sort(vector<int> &arr ,int st, int en){
        if(st >= en) return ;
        int mid = st + (en - st)/2;
        merge_sort(arr, st, mid);
        merge_sort(arr, mid + 1, en);
        count_pairs(arr, st, mid, en);
        merge(arr, st, mid, en);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge_sort(nums, 0 , n - 1);
        return cnt;
    }
};