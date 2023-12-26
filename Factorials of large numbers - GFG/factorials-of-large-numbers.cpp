//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
private:
    void multiply(vector<int> &ans, int k, int &size){
        int carry = 0;
        for(int i = 0; i < size; i++){
            int prod = ans[i] * k;
            prod += carry;
            ans[i] = prod % 10;
            carry = prod / 10;
        }
        while(carry){
            ans[size++] = carry % 10;
            carry /= 10;
        }
    }
public:
    vector<int> factorial(int N){
        vector<int> ans(10000, 0);
        ans[0] = 1;
        int size = 1;
        for(int i = 2; i <= N; i++){
            multiply(ans, i, size);
        }
        reverse(ans.begin(),ans.begin() + size);
        return vector<int>(ans.begin(), ans.begin() + size);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends