// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    map<vector<long long>, long long> memo;
    long long solve(int i, int j, int n, int arr[])
    {
        if (i > j || i >= n || j < 0)
            return 0;
        vector<long long> k{i, j};
        if (memo[k] != 0)
            return memo[k];
        int option1 = min(solve(i + 1, j - 1, n, arr), solve(i + 2, j, n, arr));
        int option2 = min(solve(i + 1, j - 1, n, arr), solve(i, j - 2, n, arr));
        memo[k] = max(arr[i] + option1, arr[j] + option2);
        return memo[k];
    }
    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        /*
        tabulation
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        for (int i = 0; i < n - 1; i++)
            dp[i][i + 1] = max(arr[i], arr[i + 1]);
        for (int gap = 3; gap < n; gap += 2)
        {
            for (int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                int option1 = min(dp[i + 1][j - 1], dp[i + 2][j]);
                int option2 = min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(arr[i] + option1, arr[j] + option2);
            }
        }
        return dp[0][n - 1];
        */
        // memoization
        memo.clear();
        solve(0, n - 1, n, arr);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends