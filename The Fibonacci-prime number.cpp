// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int fibonacciPrime(string N)
    {
        return (N == "2" || N == "3" || N == "5" || N == "13" || N == "89" || N == "233" || N == "1597" || N == "28657" || N == "514229" || N == "433494437" || N == "2971215073" || N == "99194853094755497" || N == "1066340417491710595814572169" || N == "19134702400093278081449423917" || N == "475420437734698220747368027166749382927701417016557193662268716376935476241");
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string N;
        cin >> N;

        Solution ob;

        cout << ob.fibonacciPrime(N) << "\n";
    }

    return 0;
} // } Driver Code Ends