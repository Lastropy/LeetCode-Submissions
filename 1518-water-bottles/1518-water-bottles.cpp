class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int carry = 0;
        while(numBottles){
            ans += numBottles;
            int temp = carry;
            // carry += numBottles % numExchange;
            carry = (numBottles + carry)% numExchange;
            numBottles = (numBottles + temp)/ numExchange;
        }
        return ans;
    }
};