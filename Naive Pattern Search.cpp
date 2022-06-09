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
        int n1 = pat.length();
        int n2 = txt.length();
        int i = 0;
        int j = 0;

        for (j = 0; j < n2 - n1 + 1; j++)
        {
            string s = "";
            for (i = 0; i < n1; i++)
            {
                if (txt[i + j] == pat[i])
                {
                    if (i == n1 - 1)
                    {
                        return true;
                    }
                }
                else
                {
                    break;
                }
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
}
// } Driver Code Ends