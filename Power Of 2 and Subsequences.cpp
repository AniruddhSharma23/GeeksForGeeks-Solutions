//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int mod = 1e9 + 7;
    bool check(long long x)
    {
        return (long long)ceil(log(x) / log(2)) == (long long)floor(log(x) / log(2));
    }
    long long numberOfSubsequences(int n, long long a[])
    {
        long long cnt = 0;
        for (int i = 0; i < n; i++)
            if (check(a[i]) == true)
                cnt++;
        long long ans = (long long)((1 << cnt) - 1);
        return ans % mod;
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
        long long A[N];
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends