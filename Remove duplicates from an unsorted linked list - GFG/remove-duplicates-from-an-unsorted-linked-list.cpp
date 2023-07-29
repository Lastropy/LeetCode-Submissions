//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int, int> mp;
        auto curr = head;
        Node *prev = NULL;
        while(curr){
            if(mp.count(curr -> data)){
                auto temp = curr;
                curr = curr -> next;
                prev -> next = curr;
                delete temp;
            }
            else {
                mp[curr -> data] = 1;
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
     
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends