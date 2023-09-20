//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(k == 1 || !head) return head;
        auto curr = head;
        for(int i = 1; i < k && curr; i++)
            curr = curr -> next;
        if(curr){
            auto temp = reverse(curr -> next, k);
            curr -> next = NULL;
            struct node* prev = NULL;
            auto curr = head, nxt = head -> next;
            while(curr){
                curr -> next = prev;
                prev = curr;
                curr = nxt;
                if(nxt) nxt = nxt -> next;
            }
            head -> next = temp;
            return prev;
        }
        else {
            struct node* prev = NULL;
            auto curr = head, nxt = head -> next;
            while(curr){
                curr -> next = prev;
                prev = curr;
                curr = nxt;
                if(nxt) nxt = nxt -> next;
            }
            return prev;
        }
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends