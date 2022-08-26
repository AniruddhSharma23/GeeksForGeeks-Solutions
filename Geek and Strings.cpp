//{ Driver Code Starts
// Initial Template for C++

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
        int i = 0;
        while (i < s.length())
        {
            int index = s[i] - 'a';
            if (curr->child[index] == NULL)
            {
                TrieNode *t = new TrieNode();
                curr->child[index] = t;
            }
            curr = curr->child[index];
            curr->count++;
            i++;
        }
    }
    int search(string s)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if (curr->child[index] == NULL)
                return 0;
            curr = curr->child[index];
        }
        return curr->count;
    }
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        vector<int> ans;
        root = new TrieNode();
        for (int i = 0; i < N; i++)
            insert(li[i]);
        for (int i = 0; i < Q; i++)
            ans.push_back(search(query[i]));
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int Q, N, i = 0, x;
        cin >> N;
        string s;
        string li[N];
        for (int i = 0; i < N; i++)
            cin >> li[i];
        cin >> Q;
        x = Q;
        string query[Q];
        while (Q--)
        {
            cin >> s;
            query[i++] = s;
        }

        Solution ob;
        vector<int> ans = ob.prefixCount(N, x, li, query);
        for (auto i : ans)
            cout << i << "\n";
    }
    return 0;
}
// } Driver Code Ends