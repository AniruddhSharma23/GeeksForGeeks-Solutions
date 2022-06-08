// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string reverseWords(string s)
    {
        // code here.
        string p = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            string k = "";
            while (s[i] != '.' && i < n)
            {
                k = k + s[i];
                i++;
            }
            reverse(k.begin(), k.end());
            if (i != n)
            {
                p = p + k + '.';
            }
            else
            {
                p = p + k;
            }
        }
        return p;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseWords(s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
// } Driver Code Ends