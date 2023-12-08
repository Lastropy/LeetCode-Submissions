class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n = nums.size();
    	if(n < 2) return false;
   	 
    	unordered_map<int, int> mp;
    	int pref = 0;
    	mp[0] = -1;
   	 
    	for(int i = 0; i < n; i++){
        	pref += nums[i];
        	if(mp.count(pref % k )){
            	if(i - mp[pref%k] >= 2)
                	return true;
        	}
        	else
            	mp[pref%k] = i;
    	}
    	return false;

    }
};