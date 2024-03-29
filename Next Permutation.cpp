//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // code here
        int i;
        int l;
        for (i = N - 2; i >= 0; i--)
        {
            if (arr[i + 1] > arr[i])
            {
                break;
            }
        }

        if (i < 0)
        {
            reverse(arr.begin(), arr.end());
        }
        else
        {
            for (l = N - 1; l > i; l--)
            {
                if (arr[l] > arr[i])
                {
                    break;
                }
            }

            swap(arr[l], arr[i]);
            reverse(arr.begin() + i + 1, arr.end());
        }
        return arr;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends