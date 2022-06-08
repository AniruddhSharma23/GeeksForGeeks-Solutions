// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    vector<long long> ps(long long arr[], int n)
    {
        stack<long long> st;
        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(i);
        }
        return v;
    }
    vector<long long> ns(long long arr[], int n)
    {
        stack<long long> st;
        vector<long long> v;
        for (long long i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(n);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(i);
        }
        reverse(v.begin(), v.end());
        return v;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> a = ps(arr, n);
        vector<long long> b = ns(arr, n);
        vector<long long> c;
        for (long long i = 0; i < n; i++)
        {
            c.push_back((b[i] - a[i] - 1) * arr[i]);
        }
        return *max_element(c.begin(), c.end());
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends