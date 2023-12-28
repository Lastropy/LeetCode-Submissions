//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

int upperBound(int k, int a[MAX], int n){
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = low + (high -low)/2;
        if(a[mid] > k){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int elementSmallerThanOrEqualTo(int k, int mat[MAX][MAX], int n){
    int count = 0;
    for(int i =0; i < n; i++)
        count += upperBound(k, mat[i], n);
    return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int low = mat[0][0];
  int high = mat[n-1][n-1];
  int ans = -1;
  while(low <= high){
      int mid = low + (high - low)/2;
      if(elementSmallerThanOrEqualTo(mid, mat, n) >=k){
          ans = mid;
          high = mid - 1;
      }
      else {
          low = mid + 1;
      }
  }
  return ans;
}
