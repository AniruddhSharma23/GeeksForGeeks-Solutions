//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count the number of different ways in which n can be
    // written as a sum of two or more positive integers.
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] += dp[j] * dp[i - j];
            }
        }
        return dp[n];
    }
}

//{ Driver Code Starts.
// Driver program
int
main()
{
    // taking number of testcases
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl;
    }
    return 0;
}
// } Driver Code Ends