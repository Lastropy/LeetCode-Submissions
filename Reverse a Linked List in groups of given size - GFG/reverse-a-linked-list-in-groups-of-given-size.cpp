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
    private:
    struct node* rev(struct node *h){
        if(!h || !h -> next) return h;
        struct node* prev = NULL;
        auto curr = h;
        auto nxt = h -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            if(nxt) nxt = nxt -> next;
        }
        return prev;
    }
    public:
    struct node *reverseIt (struct node *h, int k)
    { 
        if(!h || k == 1) return h;
        struct node* first = h;
        struct node* prevLast = NULL;
        while(first){
           auto kTH_Node = first;
           for(int i = 1; i < k && kTH_Node; i++) 
                kTH_Node = kTH_Node -> next;
           struct node* nxt = NULL;
           if(kTH_Node){
                nxt = kTH_Node -> next;
                kTH_Node -> next = NULL;
           }
           kTH_Node = rev(first);
           if(prevLast == NULL) h = kTH_Node;
           else prevLast -> next = kTH_Node;
           first -> next = nxt;
           prevLast = first;
           first = nxt;
        }
        return h;
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
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends