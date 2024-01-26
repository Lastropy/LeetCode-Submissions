class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        int n = l.size();
        char ans = l[0];
        int s = 0, e = n -1;
        while(s <= e){
            int m = s + (e - s) /2;
            if(l[m] <= t) s = m + 1;
            else {ans = l[m]; e = m - 1;}
        }
        return ans;
    }
};