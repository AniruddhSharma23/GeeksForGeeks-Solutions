// { Driver Code Starts
// C++ program Find concatenated string with
// uncommon characters of given strings
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2)
    {
        // Your code here
        int n1 = s1.length();
        int n2 = s2.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < n1; i++)
        {
            mp[s1[i]]++;
        }
        string s = "";
        for (int i = 0; i < n2; i++)
        {
            if (mp.find(s2[i]) != mp.end())
            {
                mp[s2[i]] = -1;
            }
        }
        for (int i = 0; i < n1; i++)
        {
            if (mp[s1[i]] != -1)
            {
                s += s1[i];
            }
        }
        for (int i = 0; i < n2; i++)
        {
            if (mp.find(s2[i]) == mp.end())
            {
                s += s2[i];
            }
        }
        if (s.length() == 0)
        {
            s = "-1";
        }
        return s;
    }
};

// { Driver Code Starts.

/* Driver program to test above function */
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        string res = obj.concatenatedString(s1, s2);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends