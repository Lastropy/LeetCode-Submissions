class Solution {
public:
    bool canEat(vector<int> &a, int sp, int tar){
        int curr = 0;
        for(int i = 0; i < a.size(); i++){
            curr += ceil((a[i] * 1.00) / sp);
        }
        return curr <= tar;
    }
    int minEatingSpeed(vector<int>& a, int t) {
        int s = 1, e = INT_MAX;
        while(s < e){
            int m = s + (e - s)/2;
            if(canEat(a,m,t)) e = m;
            else s = m + 1;
        }
        return e;
    }
};