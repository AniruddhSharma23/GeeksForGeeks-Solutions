//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
        string longestPalin(string s)
        {
            int n = s.length();
            vector<vector<bool>> dp(n, vector<bool>(n, false));
            int st = 0, len = 0;
            for (int gap = 0; gap < n; gap++)
            {
                bool check = false;
                for (int i = 0; i + gap < n; i++)
                {
                    int j = i + gap;
                    if (gap == 0)
                        dp[i][j] = true;
                    else if (gap == 1)
                    {
                        if (s[i] == s[j])
                            dp[i][j] = true;
                    }
                    else
                    {
                        if (s[i] == s[j])
                            dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] == true && check == false)
                    {
                        len = gap + 1;
                        st = i;
                        check = true;
                    }
                }
            }
            return s.substr(st, len);
        }
        */
    string longestPalin(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;
        int st = 0, len = 1;
        for (int i = 0; i < n; i++)
        {
            int l = i - 1, h = i + 1;
            while (h < n && s[h] == s[i])
                h++;
            while (l >= 0 && s[l] == s[i])
                l--;
            while (l >= 0 && h < n && s[l] == s[h])
            {
                l--;
                h++;
            }
            int k = h - l - 1;
            if (k > len)
            {
                len = k;
                st = l + 1;
            }
        }
        return s.substr(st, len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends