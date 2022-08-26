//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int dp[8][8];
    int solve(int x, int y, int t1, int t2)
    {
        if (x == t1 && y == t2)
            return dp[0][0];
        int i = abs(x - t1);
        int j = abs(y - t2);
        if (dp[i][j] != 0)
            return dp[i][j];
        int x1, x2, y1, y2;
        if (x <= t1)
        {
            if (y <= t2)
            {
                x1 = x + 1;
                y1 = y + 2;
                x2 = x + 2;
                y2 = y + 1;
            }
            else
            {
                x1 = x + 1;
                y1 = y - 2;
                x2 = x + 2;
                y2 = y - 1;
            }
        }
        else
        {
            if (y <= t2)
            {
                x1 = x - 1;
                y1 = y + 2;
                x2 = x - 2;
                y2 = y + 1;
            }
            else
            {
                x1 = x - 1;
                y1 = y - 2;
                x2 = x - 2;
                y2 = y - 1;
            }
        }
        dp[i][j] = min(solve(x1, y1, t1, t2), solve(x2, y2, t1, t2)) + 1;
        dp[j][i] = dp[i][j];
        return dp[i][j];
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {

        // dp[diff of i][diff of j] = min number of steps to reach target from i,j (0-based indexing)
        memset(dp, 0, sizeof(dp));
        int x = KnightPos[0];
        int y = KnightPos[1];
        int t1 = TargetPos[0];
        int t2 = TargetPos[1];
        int ans = -1;
        if ((x == 1 && y == 1 && t1 == 2 && t2 == 2) ||
            (x == 2 && y == 2 && t1 == 1 && t2 == 1))
            ans = 4;
        else if ((x == 1 && y == n && t1 == 2 && t2 == n - 1) ||
                 (x == 2 && y == n - 1 && t1 == 1 && t2 == n))
            ans = 4;
        else if ((x == n && y == 1 && t1 == n - 1 && t2 == 2) ||
                 (x == n - 1 && y == 2 && t1 == n && t2 == 1))
            ans = 4;
        else if ((x == n && y == n && t1 == n - 1 && t2 == n - 1) ||
                 (x == n - 1 && y == n - 1 && t1 == n && t2 == n))
            ans = 4;
        else
        {
            dp[1][0] = 3;
            dp[0][1] = 3;
            dp[1][1] = 2;
            dp[2][0] = 2;
            dp[0][2] = 2;
            dp[2][1] = 1;
            dp[1][2] = 1;

            ans = solve(x, y, t1, t2);
        }
        return ans;
    }
};
// bfs:

class Solution
{
public:
    struct cell
    {
        int x, y, d;
        cell(int i, int j, int k)
        {
            x = i;
            y = j;
            d = k;
        }
    };
    bool isSafe(int i, int j, int n)
    {
        if (i < 0 || j < 0 || i > n || j > n)
            return false;
        return true;
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
        int p1 = KnightPos[0] - 1;
        int p2 = KnightPos[1] - 1;
        int t1 = TargetPos[0] - 1;
        int t2 = TargetPos[1] - 1;
        cell s = cell(p1, p2, 0);
        queue<cell> q;
        q.push(s);
        vis[p1][p2] = true;
        vector<int> dx = {1, -1, 2, -2, 1, -1, 2, -2};
        vector<int> dy = {2, 2, 1, 1, -2, -2, -1, -1};
        while (!q.empty())
        {
            cell t = q.front();
            q.pop();
            if (t.x == t1 && t.y == t2)
                return t.d;
            for (int i = 0; i < 8; i++)
            {
                int x1 = t.x + dx[i];
                int y1 = t.y + dy[i];
                if (isSafe(x1, y1, n) && vis[x1][y1] == false)
                {
                    vis[x1][y1] = true;
                    q.push(cell(x1, y1, t.d + 1));
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends