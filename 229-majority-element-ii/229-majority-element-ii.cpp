class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int ele1 = -1, ele2 = -1;
        for(int i: nums){
            if(ele1 == i) c1++;
            else if(ele2 == i) c2++;
            else if(c1 == 0){
                ele1 = i;
                c1 = 1;
            }
            else if(c2 == 0){
                ele2 = i;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        bool m1 = false, m2 = false;
        vector<int> ans;
        int f1 = 0, f2 = 0;
        for(int i: nums){
            if( i == ele1)
                f1++;
            if(f1 > nums.size() / 3)
            {
                m1 = true;
                break;
            }
        }
        for(int i : nums){
            if(i == ele2)
                f2++;
            if(f2 > nums.size() /3)
            {
                m2 = true;
                break;
            }
        }
        if(m1) ans.push_back(ele1);
        if(m2 && ele1 != ele2) ans.push_back(ele2);
        return ans;
    }
};