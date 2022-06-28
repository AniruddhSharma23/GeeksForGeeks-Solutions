// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        // your code here
        sort(arr, arr + n, [](int a, int b)
             { return abs(a) < abs(b); });
        int mn = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            int sum = arr[i] + arr[i - 1];
            if (abs(sum) < abs(mn))
                mn = sum;
            if (abs(sum) == abs(mn))
                mn = max(mn, sum);
        }
        return mn;
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
        cout << ob.closestToZero(arr, n) << endl;
    }
} // } Driver Code Ends