// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> print_next_greater_freq(int arr[], int n)
    {
        // code here
        vector<int> v(n);
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;
        st.push(arr[n - 1]);
        v[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && mp[st.top()] <= mp[arr[i]])
                st.pop();
            int k = (st.empty()) ? -1 : st.top();
            v[i] = k;
            st.push(arr[i]);
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int arr[N];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.print_next_greater_freq(arr, n);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends