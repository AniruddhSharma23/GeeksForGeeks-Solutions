//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
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

void reorderList(struct Node *head);

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    int t, n, m, i, x;

    cin >> t;
    while (t--)
    {
        struct Node *temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends

/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
void reorderList(Node *h1)
{
    Node *s = h1;
    Node *f = s->next;
    while (f != NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
    }
    Node *a = h1;
    Node *k = s->next;
    s->next = NULL;
    Node *b = reverse(k);
    h1 = new Node(0);
    Node *curr = h1;
    while (a || b)
    {
        if (a)
        {
            curr->next = a;
            curr = curr->next;
            a = a->next;
        }
        if (b)
        {
            curr->next = b;
            curr = curr->next;
            b = b->next;
        }
    }
    h1 = h1->next;
}