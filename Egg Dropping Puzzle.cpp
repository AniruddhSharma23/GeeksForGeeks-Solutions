// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++)
        { // i->egg
            for (int j = 1; j <= k; j++)
            { // j->floor
                if (i == 1)
                    dp[i][j] = j; // we need j trails for 1 egg and j floors
                else if (j == 1)
                    dp[i][j] = 1; // we need one trial for one floor
                else
                {
                    dp[i][j] = INT_MAX;
                    for (int x = 1; x <= j; x++)
                    {
                        dp[i][j] = min(dp[i][j], 1 + max(dp[i][j - x], dp[i - 1][x - 1]));
                    }
                }
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends