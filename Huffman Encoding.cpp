// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct Node
    {
        // One of the input characters
        char data;
        // Frequency of the character
        unsigned freq;
        // Left and right child
        Node *left, *right;
        Node(char data, unsigned freq, Node *l = NULL, Node *r = NULL)
        {
            this->left = l;
            this->right = r;
            this->data = data;
            this->freq = freq;
        }
    };
    struct compare
    {
        bool operator()(Node *l, Node *r)
        {
            return (l->freq > r->freq);
        }
    };
    void create(struct Node *root, vector<string> &V, string str)
    {
        if (root == NULL)
            return;
        if (root->data != '$')
        {
            V.push_back(str);
            return;
        }
        create(root->left, V, str + "0");
        create(root->right, V, str + "1");
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, compare> pq;
        for (int i = 0; i < N; i++)
        {
            Node *curr = new Node(S[i], f[i]);
            pq.push(curr);
        }
        while (pq.size() > 1)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            Node *temp = new Node('$', a->freq + b->freq, a, b);
            pq.push(temp);
        }
        vector<string> V;
        create(pq.top(), V, "");
        return V;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends