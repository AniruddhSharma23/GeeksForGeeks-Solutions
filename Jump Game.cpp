//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int canReach(int A[], int n)
    {
        // code here
        int maxReachable = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxReachable)
                return false;
            maxReachable = max(maxReachable, i + A[i]);
        }
        return true;
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

        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.canReach(A, N) << endl;
    }
    return 0;
}
// } Driver Code Ends