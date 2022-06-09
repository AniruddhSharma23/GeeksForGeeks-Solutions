// { Driver Code Starts
// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt)
    {
        // Your code here
        int m = txt.length();
        int n = pat.length();
        for (int i = 0; i < m - n + 1; i++)
        {
            string r = txt.substr(i, n);
            if (r == pat)
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string s, p;
        cin >> s >> p;
        Solution obj;
        if (obj.search(p, s))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends