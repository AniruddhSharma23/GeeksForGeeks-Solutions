// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    int lps(string s)
    {
        int n = s.size();
        vector<int> lps(n);
        lps[0] = 0;
        int i = 1, len = 0;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                lps[i++] = ++len;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i++] = 0;
                }
            }
        }
        return len;
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
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
// } Driver Code Ends