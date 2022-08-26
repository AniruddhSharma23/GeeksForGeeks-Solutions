//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    map<vector<long long>, long long> memo;
    int solve(int i, int j, int n, vector<int> &nums)
    {
        if (i > j || j < 0 || i >= n)
            return 0;
        vector<long long> k{i, j};
        if (memo[k] != 0)
            return memo[k];
        int option1 = min(solve(i + 1, j - 1, n, nums), solve(i + 2, j, n, nums));
        int option2 = min(solve(i + 1, j - 1, n, nums), solve(i, j - 2, n, nums));
        memo[k] = max(nums[i] + option1, nums[j] + option2);
        return memo[k];
    }
    int maxCoins(vector<int> &nums, int n)
    {
        int f = solve(0, n - 1, n, nums);
        return f;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}

// } Driver Code Ends