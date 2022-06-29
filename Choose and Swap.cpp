// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string chooseandswap(string a)
    {
        int n = a.length();
        map<char, int> mp;
        for (char c = 'a'; c <= 'z'; c++)
            mp[c] = -1;
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]] == -1)
                mp[a[i]] = i;
        }
        bool found = false;
        char c1, c2;
        for (int i = 0; i < n; i++)
        {
            for (char p = 'a'; p < a[i]; p++)
            {
                if (mp[p] > i)
                {
                    found = true;
                    c2 = p;
                    c1 = a[i];
                    break;
                }
            }
            if (found == true)
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == c1)
                a[i] = c2;
            else if (a[i] == c2)
                a[i] = c1;
        }
        return a;
    }
};

// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}
// } Driver Code Ends