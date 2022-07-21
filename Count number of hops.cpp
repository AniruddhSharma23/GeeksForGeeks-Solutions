//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count the number of ways in which frog can reach the top.
    int mod = 1e9 + 7;
    long long countWays(int n)
    {

        long long a = 1, b = 2, c = 4;
        if (n == 1)
            return a;
        if (n == 2)
            return b;
        if (n == 3)
            return c;
        for (long long i = 4; i <= n; i++)
        {
            long long old_c = c % mod;
            c = (a % mod + b % mod + c % mod) % mod;
            a = b % mod;
            b = old_c % mod;
        }
        return c % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}

// } Driver Code Ends