//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int nCr(int n, int r)
    {
        // code here
        if (n < r)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = i;
            dp[i][i] = 1;
            dp[i][0] = 1;
        }
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        return dp[n][r] % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}
// } Driver Code Ends