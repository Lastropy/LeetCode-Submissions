class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        // string res = string(num1.size() + num2.size(), '0');
        int tot_size = num1.size() + num2.size();
        string res = string( tot_size , '0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int pos = i + j + 1;
                int dig = (res[pos] - '0') + ((num2[j] - '0') * (num1[i] -  '0')) + carry;
                res[pos] = '0' + (dig % 10);
                carry = dig / 10;
                // cout << res << " | " << carry << endl;
            }
            if (carry)
                res[i] += carry;
        }
        int beg = 0;
        while (beg < res.size() && res[beg] == '0')
            beg++;
        return res.substr(beg);
        }
};