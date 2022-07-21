//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    int CountWays(string s)
    {
        // Code here
        int n = s.length();
        int dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
                dp = dp1 % mod;
            if ((i + 1 < n) && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] <= '6')))
                dp = (dp + dp2) % mod;
            dp2 = dp1 % mod;
            dp1 = dp % mod;
            dp = 0;
        }
        return dp1 % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends