// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findTime(string S1, string S2)
    {
        // code here
        int n1 = S1.length();
        int n2 = S2.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < n1; i++)
            mp[S1[i]] = i;
        int index = 0;
        int k = 0;
        for (int i = 0; i < n2; i++)
        {
            k += abs(index - mp[S2[i]]);
            index = mp[S2[i]];
        }
        return k;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S1, S2;
        cin >> S1;
        cin >> S2;

        Solution ob;
        cout << ob.findTime(S1, S2) << endl;
    }
    return 0;
} // } Driver Code Ends