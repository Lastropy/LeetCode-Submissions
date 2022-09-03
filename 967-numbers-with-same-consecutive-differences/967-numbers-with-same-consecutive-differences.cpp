class Solution {
public:
//     void f(int n, int k, int prev, vector<int> &ans, string curr= ""){
//         if(n == 0){
//             ans.push_back(stoi(curr));
//             return;
//         }
        
        
//         if(prev == -1){
//             for(int i = 1; i <= 9; i++){
//                 f(n-1,k, i, ans, curr + to_string(i));       
//             }
//         }
//         else{
//             int pos1 = prev + k;
//             int pos2 = prev - k;
//             if(pos1 >= 0 && pos1 <= 9) 
//                 f(n-1, k , pos1, ans, curr + to_string(pos1));
//             if(pos1 != pos2 && pos2 >= 0 && pos2 <= 9) 
//                 f(n-1, k , pos2, ans, curr + to_string(pos2));
//         }
//     }
    void f(int n, int k, int res, vector<int> &ans){
        if(n == 0){
            ans.push_back(res);
            return;
        }

        int pos1 = (res % 10) + k;
        int pos2 = (res % 10) - k;
        if(pos1 >= 0 && pos1 <= 9) 
            f(n-1, k , res*10 + pos1, ans);
        if(pos1 != pos2 && pos2 >= 0 && pos2 <= 9) 
            f(n-1, k , res*10 + pos2, ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
            f(n - 1, k, i, ans);
        return ans;
    }
};