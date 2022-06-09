// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        vector<string> v;
        int n = S.length();
        string k = "";
        for (int i = 0; i < n; i++)
        {
            if (S[i] == '.')
            {
                v.push_back(k);
                k = "";
            }
            else
            {
                k += S[i];
            }
        }
        v.push_back(k);
        string p = "";
        for (int i = v.size() - 1; i > 0; i--)
        {
            p += v[i];
            p += '.';
        }
        p += v[0];
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
} // } Driver Code Ends