class Solution
{
public:
    int maxCoins(vector<int> &a, int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> v;
        v.push_back(1);
        for (int x : a)
            v.push_back(x);
        v.push_back(1);
        for (int i = 0; i < n + 2; i++)
            for (int j = 0; j < n + 2; j++)
                dp[i][j] = 0;
        for (int i = n; i >= 1; i--)
            for (int j = i; j <= n; j++)
                for (int k = i; k <= j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + v[i - 1] * v[k] * v[j + 1]);
        return dp[1][n];
    }
};