// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        // Code here
        int n = nums.size();
        pair<int, int> arrPos[n];
        for (int i = 0; i < n; i++)
        {
            arrPos[i].first = nums[i];
            arrPos[i].second = i;
        }
        sort(arrPos, arrPos + n);

        vector<bool> vis(n, false);

        // Initialize result
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            if (vis[i] || arrPos[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;

                j = arrPos[j].second;
                cycle_size++;
            }

            if (cycle_size > 0)
            {
                ans += (cycle_size - 1);
            }
        }

        return ans;
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
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends