// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

class Solution
{
public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> v;
        unordered_set<int> s;

        Node *curr1 = root1, *curr2 = root2;

        traverse(curr1, s);

        vector<int> t2;

        traverse(curr2, t2);

        for (int i = 0; i < t2.size(); i++)
        {
            if (s.find(t2[i]) != s.end())
                v.push_back(t2[i]);
        }

        return v;
    }

    void traverse(Node *root, unordered_set<int> &s)
    {
        if (root != NULL)
        {
            s.insert(root->data);
            traverse(root->left, s);
            traverse(root->right, s);
        }
    }

    void traverse(Node *root, vector<int> &s)
    {
        if (root != NULL)
        {
            traverse(root->left, s);
            s.push_back(root->data);
            traverse(root->right, s);
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);
        Solution ob;
        vector<int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }

    return 1;
} // } Driver Code Ends