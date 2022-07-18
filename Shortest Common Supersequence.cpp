//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.
    string lcs(string &s1, string &s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<string>> dp(n1 + 1, vector<string>(n2 + 1, ""));
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j] + s1[i];
                else
                    dp[i + 1][j + 1] = (dp[i + 1][j].length() > dp[i][j + 1].length()) ? dp[i + 1][j] : dp[i][j + 1];
            }
        }
        return dp[n1][n2];
    }
    int shortestCommonSupersequence(string str1, string str2, int m, int n)
    {
        // code here
        string k = lcs(str1, str2);
        string ans = "";
        int i = 0, j = 0;
        for (char c : k)
        {
            while (str1[i] != c) // add all non-common characters of str1
                ans += str1[i++];
            while (str2[j] != c) // add all non-common characters of str2
                ans += str2[j++];
            ans += c; // add the common character
            i++;
            j++;
        }
        ans = ans + str1.substr(i) + str2.substr(j);
        return ans.length();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking total testcases
    cin >> t;
    while (t--)
    {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}

// } Driver Code Ends