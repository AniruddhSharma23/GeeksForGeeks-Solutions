//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<int>> vec = uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}

// } Driver Code Ends

/*You are required to complete this function*/
struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    bool insert(int M[MAX][MAX], int row, int col)
    {
        Node *node = root;
        bool flag = false;
        for (int c = 0; c < col; c++)
        {
            int num = M[row][c];
            if (!node->containsKey(num))
            {
                node->put(num, new Node());
                flag = true;
            }
            node = node->get(num);
        }
        return flag;
    }
};
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    Trie trie;
    vector<vector<int>> ans(0, vector<int>(col));
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        if (trie.insert(M, i, col))
        {
            ans.resize(ans.size() + 1, vector<int>(col));
            for (int j = 0; j < col; j++)
            {
                ans[k][j] = M[i][j];
            }
            k++;
        }
    }
    return ans;
}
