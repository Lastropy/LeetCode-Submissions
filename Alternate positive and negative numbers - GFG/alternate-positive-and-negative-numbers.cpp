//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> neg;
	    vector<int> pos;
	    for(int i = 0; i < n; i++){
	        if(arr[i] < 0)
	            neg.push_back(arr[i]);
	        else
	            pos.push_back(arr[i]);
	    }
	    int curr1 = 0, curr2 = 0;
	    for(int i = 0; i < n; i++){
	        if(i % 2 == 0){
	            if(curr1 < pos.size()){
	                arr[i] = pos[curr1++];
	            } else if( curr2 < neg.size()){
	                arr[i] = neg[curr2++];
	            }
	        } else {
	            if(curr2 < neg.size()){
	                arr[i] = neg[curr2++];
	            } else if( curr1 < pos.size()){
	                arr[i] = pos[curr1++];
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends