// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> tail;
        tail.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > tail.back())
                tail.push_back(a[i]);
            else
                tail[findCeil(tail, a[i])] = a[i];
        }
        return tail.size();
    }
    int findCeil(vector<int> &tail, int x)
    {
        int k = tail.size();
        int l = 0, r = k - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (tail[m] >= x)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends