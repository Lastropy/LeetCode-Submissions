class Solution {
public:
    int findNthDigit(int n) {
        // // 100th digit
        // // [1, 100]
        // // 35 -> 3 => ?? , 5 => ??
        // int s = 1, e = n;
        // while(s <= e){
        //     int m = s + (e-s)/2;
        //     if()
        // } 
        // return;
        
        
        
        
        
        //linear search
        // [1-9] : {9 - 1 + 1} * 1 => 9 digits => 9 * 1
        // [10 - 99] : {99 - 10 + 1} * 2 => 180 digits => 90 * 2
        // [100 - 999]: {999 - 100 + 1} * 3 => 2700 digits. => 900 * 3
        // [1000 - 9999] : {9999 - 1000 + 1} * 4 => 36000 digits => 9000 * 4
        
        // Step - 1: Find number of digits in our answer;
        
        int base = 9;
        int len = 1;
        int curr = 1;
        while(n > 1LL * base * len){
            n -= base * len;
            len++;
            base *= 10;
            curr *= 10;
        }
        curr += ((n - 1)/len);
        int pos_of_dig = len - ((n-1)% len);
        int ans = -1;
        while(pos_of_dig){
            ans = curr % 10;
            curr /= 10;
            pos_of_dig--;
        }
        // cout << curr << " | "<< pos_of_dig << endl;
        return ans;
    }
};