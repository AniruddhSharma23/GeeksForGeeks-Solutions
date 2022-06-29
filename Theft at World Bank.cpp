// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPerfect(long long n)
    {
        long long sq = sqrt(n);
        return (sq * sq == n);
    }
    long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p)
    {
        // Code here.
        typedef pair<long double, long long> pi;
        vector<pi> ratio;
        for (int i = 0; i < N; i++)
        {
            long double x = (long double)((long double)p[i] / (long double)w[i]);
            ratio.push_back(make_pair(x, w[i]));
        }
        sort(ratio.begin(), ratio.end());
        long double s = 0;
        int i = N - 1;
        while (i >= 0 && C > 0)
        {
            long long wt = ratio[i].second;
            long double rt = ratio[i].first;
            if (!isPerfect(wt))
            {
                s += min(C, wt) * rt;
                C -= min(C, wt);
            }
            i--;
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        long long C;
        cin >> n >> C;
        vector<long long> w(n), p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> w[i] >> p[i];
        }
        Solution ob;
        long double ans = ob.maximumProfit(n, C, w, p);
        cout << fixed << setprecision(3) << ans << "\n";
    }
    return 0;
} // } Driver Code Ends