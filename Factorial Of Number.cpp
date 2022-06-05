// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int digitsInFactorial(int n)
    {
        // code here
        if (n < 0)
            return 0;

        // base case
        if (n <= 1)
            return 1;

        // else iterate through n and calculate the
        // value
        double digits = 0;
        for (int i = 2; i <= n; i++)
            digits += log10(i);

        return floor(digits) + 1;
    }
};

// { Driver Code Starts.

int main()
{
    int T;

    // taking testcases
    cin >> T;
    while (T--)
    {
        int N;

        // taking N
        cin >> N;
        Solution ob;
        // calling method digitsInFactorial()
        cout << ob.digitsInFactorial(N) << endl;
    }
    return 0;
}
// } Driver Code Ends