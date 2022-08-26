//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int nineDivisors(long long int N)
    {

        int sq = sqrt(N);
        vector<bool> isPrime(sq + 1, true);
        for (int i = 2; i <= sqrt(sq) + 1; i++)
            if (isPrime[i] == true)
                for (int j = i * i; j <= sq; j += i)
                    isPrime[j] = false;
        vector<int> primes;
        for (int i = 2; i <= sq; i++)
            if (isPrime[i] == true)
                primes.push_back(i);
        int np = primes.size();
        int ans = 0;
        for (int i = 0; i < np; i++)
        {
            long long q = sq / primes[i];
            ans += (upper_bound(primes.begin(), primes.begin() + i, q) - primes.begin());
        }
        for (int i = 0; i < np; i++)
        {
            long long p = primes[i] * primes[i];
            if (pow(p, 4) <= N)
                ans++;
            else
                break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends