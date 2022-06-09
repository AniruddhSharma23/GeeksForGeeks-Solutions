// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string s)
    {
        // Your code here
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        int m = 0;
        for (auto &x : mp)
        {
            if (x.second > m)
            {
                m = x.second;
            }
        }
        vector<char> v;
        for (auto &x : mp)
        {
            if (x.second == m)
            {
                v.push_back(x.first);
            }
        }
        sort(v.begin(), v.end());
        return v[0];
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;
    }
} // } Driver Code Ends