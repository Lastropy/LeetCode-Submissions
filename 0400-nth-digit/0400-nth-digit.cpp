class Solution {
public:
    int lengthOfNumber(int n){
        int length = 0;
        while(n){
            length++;
            n/=10;
        }
        return length;
    }
    
    long long int digitsOccured(int n){
        if(n == 0) return 0;
        int digNum = lengthOfNumber(n);
        long long int len = 1, base = 9, count = 0;
        
        while(len < digNum)
        {
            count += base * len;
            len++;
            base *= 10;
        }
        count += (n - pow(10, len - 1) + 1) * (len);
        return count;
    }
    
    int findNthDigit(int n) {
        // binary search
        // min answer possible = 1
        // max answer possible = n
        int s = 1, e = n, mid;
        
        // Step - 1: Pick a number in range;
        while(s <= e){
            mid = s + (e-s)/2;
            
            // Step - 2: Find Number of digits that have occured till (mid - 1)
            long long int occured = digitsOccured(mid-1);
            int length = lengthOfNumber(mid);
            // cout << (mid) << " | " << length << " | " << occured << endl;
             
            if(occured >= n) e = mid - 1;
            else if(occured < n && occured + length >= n){
                n = length - (n - occured);
                break;
            }
            else s = mid + 1;
        }
        
        int ans = -1;
        for(int i = 0; i <= n; i++){
            ans = mid % 10;
            mid /= 10;
        }
        return ans;
    }
};