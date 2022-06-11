// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<long long> Factor(long long N)
    {
        long long i;
        vector<long long> v;
        for (i = 1; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                if (i * i == N)
                {
                    v.push_back(i);
                }
                else
                {
                    v.push_back(N / i);
                    v.push_back(i);
                }
            }
        }
        return v;
    }
    int isPerfectNumber(long long N)
    {
        // code here
        vector<long long> v = Factor(N);
        long long s = accumulate(v.begin(), v.end(), 0);
        return ((s - N) == N);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
} // } Driver Code Ends