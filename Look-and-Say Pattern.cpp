//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string conv(string s)
    {
        int n = s.length();
        string ans = "";
        int cnt = 1;
        char c = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] != c)
            {
                ans += to_string(cnt);
                ans += c;
                c = s[i];
                cnt = 1;
            }
            else
                cnt++;
        }
        ans += to_string(cnt);
        ans += c;
        return ans;
    }
    string lookandsay(int n)
    {
        vector<string> dp(n + 1);
        dp[1] = "1";
        if (n == 1)
            return dp[1];
        dp[2] = "11";
        for (int i = 3; i <= n; i++)
            dp[i] = conv(dp[i - 1]);
        return dp[n];
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
        Solution obj;
        cout << obj.lookandsay(n) << endl;
    }
    return 0;
}
// } Driver Code Ends