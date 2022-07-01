// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isSafe(int row, int col, int n, int m, vector<vector<int>> &grid)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;
        return true;
    }
    void solve(int row, int col, int n, int m, vector<vector<int>> &grid, vector<int> &v, vector<vector<int>> &ans)
    {
        if (row == n - 1 && col == m - 1)
        {
            ans.push_back(v);
            return;
        }
        int x1 = row + 1, y1 = col;
        if (isSafe(x1, y1, n, m, grid))
        {
            v.push_back(grid[x1][y1]);
            solve(x1, y1, n, m, grid, v, ans);
            v.pop_back();
        }
        x1 = row, y1 = col + 1;
        if (isSafe(x1, y1, n, m, grid))
        {
            v.push_back(grid[x1][y1]);
            solve(x1, y1, n, m, grid, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(grid[0][0]);
        int x = 0, y = 0;
        solve(x, y, n, m, grid, v, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends