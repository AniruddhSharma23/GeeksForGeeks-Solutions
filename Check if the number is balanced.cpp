// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool balancedNumber(string N)
    {
        // code here
        int l = N.length();
        int m = l / 2;
        int s = 0;
        for (int i = 0; i < l; i++)
        {
            if (i < m)
            {
                s += N[i];
            }
            if (i > m)
            {
                s -= N[i];
            }
        }
        return (s == 0);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string N;
        cin >> N;
        Solution ob;
        cout << ob.balancedNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends