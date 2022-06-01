// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimum_difference(vector<int> nums)
    {
        // Code here
        int n = nums.size();
        int m = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            m = min(nums[i] - nums[i - 1], m);
        }
        return m;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.minimum_difference(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends