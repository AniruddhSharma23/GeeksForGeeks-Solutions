//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
public:
    TrieNode *child[26];
    int count;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        count = 0;
    }
};
class Solution
{
public:
    TrieNode *root;
    void insert(string s)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if (curr->child[index] == NULL)
            {
                TrieNode *t = new TrieNode();
                curr->child[index] = t;
            }
            curr = curr->child[index];
            curr->count++;
        }
    }
    int search(string s, int k)
    {
        TrieNode *curr = root;
        int i = 0;
        while (i < k)
        {
            int index = s[i] - 'a';
            if (curr->child[index] == NULL)
                return 0;
            curr = curr->child[index];
            i++;
        }
        return curr->count;
    }
    int klengthpref(string arr[], int n, int k, string str)
    {
        root = new TrieNode();
        int ns = str.length();
        if (k > ns)
            return 0;
        for (int i = 0; i < n; i++)
            insert(arr[i]);
        return search(str, k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> arr[i];
        }
        int k;
        cin >> k;
        string str;
        cin >> str;

        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0;
}

// } Driver Code Ends