// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        // Your code here
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        for (auto &x : mp)
        {
            if (x.second > 1)
            {
                return false;
            }
        }
        return true;
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
        cout << obj.isIsogram(s) << endl;
    }
    return 0;
} // } Driver Code Ends