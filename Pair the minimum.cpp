// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int Pair_minimum(int *arr, int n)
    {
        // Complete the functiom
        sort(arr, arr + 2 * n);
        int k = 0;
        for (int i = 0; i <= n; i++)
        {
            k = max(k, arr[i] + arr[(2 * n) - i - 1]);
        }
        return k;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int arr[2 * n + 1];
        for (int i = 0; i < 2 * n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.Pair_minimum(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends