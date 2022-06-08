// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int m = 1000000007;
        vector<long long> v(n + 1, 0);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        for (long long i = 3; i <= n; i++)
        {
            v[i] = ((v[i - 1] % m) + (v[i - 2]) % m) % m;
        }
        return v[n] % m;
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
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends