//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
           mp[a[i]]++;
        }
        int ans = 1;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int start = (it -> first);
            if(mp.count(start-1) == 0){
                while(mp.count(start+1)){
                    start++;
                }
                ans = max(ans, start - (it -> first) + 1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends