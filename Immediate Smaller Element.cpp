//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void immediateSmaller(int *arr, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(arr[i]);
        arr[n - 1] = -1;

        int i = n - 2;
        while (!st.empty() && i >= 0)
        {
            int k = st.top();
            st.pop();
            if (arr[i] > k)
                arr[i] = k;
            else
                arr[i] = -1;
            i--;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends