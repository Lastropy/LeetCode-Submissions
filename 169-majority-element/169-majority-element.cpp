class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int ele;
        for(int i : nums){
            if(c == 0){
                ele = i;
            }
            if(i == ele)
                c++;
            else
                c--;
        }
        return ele;
    }
};