//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isSafe(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &count)
    {
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {-1, 1, 0, -1, 1, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();
        if (grid[i][j] == 1)
        {
            if (vis[i][j] == false)
            {
                count++;
                vis[i][j] = true;
            }
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (isSafe(x, y, m, n) && grid[x][y] == 1 && vis[x][y] == false)
                    dfs(x, y, grid, vis, count);
            }
        }
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int ans = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == false)
                {
                    int curr = 0;
                    dfs(i, j, grid, vis, curr);
                    ans = max(ans, curr);
                }
            }
        }
        if (ans == INT_MIN)
            ans = 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends