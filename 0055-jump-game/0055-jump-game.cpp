class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int goal = n - 1;
        for(int i = n - 2; i >= 0; i--){
            if(a[i] + i >= goal) goal = i;
            else continue;
        }
        return (goal == 0);
    }
};