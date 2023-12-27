//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int upperBound(vector<int> &a, int k){
        int low = 0, high = a.size() - 1;
        int ans = high + 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(a[mid] <= k)
                low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;   
            }
        }
        return ans;
    }
    int elementsLessThanOrEqualTo(int k, vector<vector<int>> &mat){
        int count = 0;
        for(int i = 0; i < mat.size(); i++)
            count += upperBound(mat[i], k);
        return count;
    }
    
    int median(vector<vector<int>> &mat, int n, int m){
        int low = INT_MAX, high = INT_MIN, tar = (n * m)/2;
        for(int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(elementsLessThanOrEqualTo(mid, mat) <= tar){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends