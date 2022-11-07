class Solution {
public:
    int maximum69Number (int num) {
        int nod = log10(num);
        int base = pow(10, nod);

        while(base){
            // cout << (num / base) % 10 << endl;
            if((num / base) % 10 == 6){
                num += 3 * base;
                break;
            }
            base /= 10;
        }
        return num;
    }
};