// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string smallestNumber(int S, int D)
    {
        // code here
        if (S > 9 * D)
            return "-1";
        string s = "";
        while (D--)
        {
            if (S >= 9)
            {
                s += '9';
                S -= 9;
            }
            else
            {
                s += to_string(S);
                S = 0;
            }
        }
        reverse(s.begin(), s.end());
        if (s[0] == '0')
        {
            int i = 0;
            while (s[i] == '0' && i < s.length())
            {
                i++;
            }
            s[i]--;
            s[0] = '1';
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S, D) << endl;
    }
    return 0;
} // } Driver Code Ends