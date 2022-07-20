class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == 1) return vector<int>({arr[0]});
        if(n == k) return arr;
        if(x < arr[0])
            return vector<int>(arr.begin(), arr.begin()+ k);
        else if(x > arr[n -1])
            return vector<int>(arr.begin() + n - k, arr.end());
        priority_queue<pair<int,int>> max_heap;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            max_heap.push({abs(arr[i]-x),arr[i]});
            if(max_heap.size() > k)
                max_heap.pop();
        }
        while(!max_heap.empty()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};