//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int mod = 1e9 + 7;
    long long int countPS(string s)
    {
        int n = s.length();
        vector<vector<long long>> dp(n + 1, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                if (s[i] == s[j])
                {
                    dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod + 1) % mod;
                }
                else
                {
                    dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod - dp[i + 1][j - 1] % mod + mod) % mod;
                }
            }
        }
        return dp[0][n - 1] % mod;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends