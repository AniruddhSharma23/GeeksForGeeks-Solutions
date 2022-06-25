// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        // code here.
        unordered_map<string, int> mp;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
            k = max(mp[arr[i]], k);
        }
        string res = "";
        int m = 0;
        for (auto &x : mp)
        {
            if (x.second < k)
            {
                m = max(m, x.second);
                if (m == x.second)
                {
                    res = x.first;
                }
            }
        }
        return res;
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
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends