// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main()
{
    // code
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
} // } Driver Code Ends

// Function to find out the number of ways we can place a black and a
// white Knight on this chessboard such that they cannot attack each other.
bool isSafe(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}
long long numOfWays(int n, int m)
{
    // write code here
    long long ans = 0;
    long long k;
    long long mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            k = (n * m) - 1;
            if (isSafe(i + 2, j + 1, n, m))
                k--;
            if (isSafe(i + 2, j - 1, n, m))
                k--;
            if (isSafe(i + 1, j + 2, n, m))
                k--;
            if (isSafe(i + 1, j - 2, n, m))
                k--;
            if (isSafe(i - 1, j + 2, n, m))
                k--;
            if (isSafe(i - 1, j - 2, n, m))
                k--;
            if (isSafe(i - 2, j + 1, n, m))
                k--;
            if (isSafe(i - 2, j - 1, n, m))
                k--;
            ans = (ans + k) % mod;
        }
    }
    return ans % mod;
}