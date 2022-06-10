// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *swapkthnode(Node *head, int num, int K);

void addressstore(Node **arr, Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp)
    {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node **before, Node **after, int num, int K)
{
    if (K > num)
        return 1;
    return (before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, K, firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node *head = new Node(firstdata);
        Node *tail = head;
        for (int i = 0; i < num - 1; i++)
        {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends

// User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node *head, int num, int k)
{

    // Check if k is valid
    int n = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        n++;
    }
    if (n < k)
        return head;

    // If x (kth node from start) and
    // y(kth node from end) are same
    if ((2 * k) - 1 == n)
        return head;

    // Find the kth node from the beginning of
    // the linked list. We also find
    // previous of kth node because we
    // need to update next pointer of
    // the previous.
    Node *x = head;
    Node *x_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        x_prev = x;
        x = x->next;
    }

    // Similarly, find the kth node from
    // end and its previous. kth node
    // from end is (n-k+1)th node from beginning
    Node *y = head;
    Node *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++)
    {
        y_prev = y;
        y = y->next;
    }

    // If x_prev exists, then new next of
    // it will be y. Consider the case
    // when y->next is x, in this case,
    // x_prev and y are same. So the statement
    // "x_prev->next = y" creates a self loop.
    // This self loop will be broken
    // when we change y->next.
    if (x_prev)
        x_prev->next = y;

    // Same thing applies to y_prev
    if (y_prev)
        y_prev->next = x;

    // Swap next pointers of x and y.
    // These statements also break self
    // loop if x->next is y or y->next is x
    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;

    // Change head pointers when k is 1 or n
    if (k == 1)
        head = y;
    if (k == n)
        head = x;

    return head;
}
