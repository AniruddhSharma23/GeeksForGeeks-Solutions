// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string chooseandswap(string a)
    {
        // Code Here
        int n = a.length();
        char k = a[0];
        char p = 'A';
        for (char c : a)
        {
            if (c < k)
                p = min(p, c);
        }
        for (char c : a)
        {
            if (c == p)
            {
                c = k;
            }
            else if (c == k)
            {
                c = p;
            }
        }
        return s;
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