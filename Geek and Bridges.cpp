
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n2; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n1][n2] << endl;
    }
    return 0;
}