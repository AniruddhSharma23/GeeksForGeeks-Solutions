//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> printUnsorted(int arr[], int n)
    {
        // code here
        int i = 0;
        int j = n - 1;
        while (i < n - 1 && arr[i] <= arr[i + 1])
            i++;
        while (j > 0 && arr[j] >= arr[j - 1])
            j--;
        if (i == n - 1)
            return {0, 0};
        int l = 0, r = n - 1;
        int mn = arr[i];
        int mx = arr[i];
        for (int k = i + 1; k <= j; k++)
        {
            mn = min(mn, arr[k]);
            mx = max(mx, arr[k]);
        }
        while (arr[l] <= mn && l <= i)
            l++;
        while (arr[r] >= mx && r >= j)
            r--;
        return {l, r};
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends