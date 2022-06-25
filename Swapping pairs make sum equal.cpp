// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        // Your code goes here
        long long s1 = 0;
        long long s2 = 0;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            s1 += A[i];
            st.insert(A[i]);
        }
        for (int j = 0; j < m; j++)
        {
            s2 += B[j];
        }
        long long d = s1 - s2;
        if (d % 2 == 1)
            return -1;
        for (int i = 0; i < m; i++)
        {
            if (st.find((d / 2) + B[i]) != st.end())
            {
                return 1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends