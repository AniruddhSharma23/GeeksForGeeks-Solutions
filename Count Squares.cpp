// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSquares(int N)
    {
        // code here
        int sq = sqrt(N);
        if (sq * sq == N)
        {
            return sq - 1;
        }
        else
        {
            return sq;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
} // } Driver Code Ends