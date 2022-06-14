// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int check(int n)
    {
        int k = 0;
        for (int i = 5; n / i >= 1; i *= 5)
        {
            k += n / i;
        }
        return k;
    }
    int findNum(int n)
    {
        // complete the function here
        int s = 0;
        int e = 5 * n;
        int ans = 0;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (check(m) >= n)
            {
                ans = m;
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
    return 0;
} // } Driver Code Ends