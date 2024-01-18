class Solution {
public:
    string strWithout3a3b(int a, int b, char c1 = 'a', char c2 = 'b', string res = "") {
        if(b > a) return strWithout3a3b(b,a, c2, c1);
        while(a > b && a > 0 && b > 0){
            res += string(2, c1) + string(1, c2);
            a -= 2;
            b -= 1;
        }
        while(a > 0|| b > 0){
            if(a >= 2) {res += string(2, c1); a--;}
            else if(a > 0) res += string(1, c1);
            
            if(b >= 2) {res += string(2, c2); b--;}
            else if(b > 0) res += string(1, c2);
            a--;
            b--;
        }
        return res;
    }   
};

// string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
//   if (B > A) return strWithout3a3b(B, A, b, a);
//   while (A-- > 0) {
//     res += a;
//     if (A > B) res += a, A--;
//     if (B-- > 0) res += b;
//   }
//   return res;
// }