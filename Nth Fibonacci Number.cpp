// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {
        // code here
        long long m = 1000000007;
        vector<long long> v(n + 1, 0);
        v[0] = 0;
        v[1] = 1;
        for (long long i = 2; i <= n; i++)
        {
            v[i] = ((v[i - 1] % m) + (v[i - 2] % m)) % m;
        }
        return v[n] % m;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
// } Driver Code Ends