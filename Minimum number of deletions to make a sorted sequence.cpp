// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
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
    int lcs(int arr[], int n)
    {
        vector<int> tail(1, arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > tail.back())
                tail.push_back(arr[i]);
            else
                tail[findCeil(tail, arr[i])] = arr[i];
        }
        return tail.size();
    }
    int minDeletions(int arr[], int n)
    {
        // Your code goes here
        int l = lcs(arr, n);
        return n - l;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.minDeletions(arr, n) << "\n";
    }
    return 0;
} // } Driver Code Ends