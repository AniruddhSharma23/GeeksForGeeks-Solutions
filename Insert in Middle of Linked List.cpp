#include <bits/stdc++.h>
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

// function to display the linked list
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertInMiddle(Node *head, int x);

int main()
{
    int T, n, x;
    cin >> T;
    while (T--)
    {
        cin >> n >> x;

        struct Node *head = new Node(x);
        struct Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        cin >> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}
// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
Node *insertInMiddle(Node *head, int x)
{
    // Cpde here
    Node *curr = head;
    int len = 1;
    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }
    int mid = len / 2;
    Node *temp = new Node(x);
    Node *p = head;
    while (mid != 1)
    {
        p = p->next;
        mid--;
    }
    temp->next = p->next;
    p->next = temp;
    return head;
}