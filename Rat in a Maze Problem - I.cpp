// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void backtrack(int r, int c, vector<vector<bool>> &vis, vector<string> &s, string ans, vector<vector<int>> &m, int n)
    {
        if (r < 0 || r > n - 1 || c < 0 || c > n - 1 || vis[r][c] == 1 || m[r][c] == 0)
            return;
        if (r == n - 1 && c == n - 1)
        {
            s.push_back(ans);
            return;
        }
        vis[r][c] = 1;
        backtrack(r - 1, c, vis, s, ans + "U", m, n);
        backtrack(r + 1, c, vis, s, ans + "D", m, n);
        backtrack(r, c - 1, vis, s, ans + "L", m, n);
        backtrack(r, c + 1, vis, s, ans + "R", m, n);
        vis[r][c] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vector<string> s;
        backtrack(0, 0, vis, s, "", m, n);
        return s;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends