//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<long long> dp;
    int mod = 1e9 + 7;
    long long int solve(int n)
    {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        int ways = 0;
        int a = solve(n - 1) % mod;
        int b = ((n - 1) % mod * (solve(n - 2) % mod)) % mod;
        return dp[n] = (a % mod + b % mod) % mod;
    }
    int countFriendsPairings(int n)
    {
        // code here
        dp.assign(n + 1, -1);
        return solve(n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// } Driver Code Ends