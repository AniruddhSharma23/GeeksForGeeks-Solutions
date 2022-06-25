// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string fractionToDecimal(int n, int d)
    {
        // Code here
        unordered_map<int, int> mp;
        string s = "";
        int i = n / d;
        int r = n % d;
        s += to_string(i);
        if (r == 0)
            return s;
        s += ".";
        int index = s.size();
        while (r)
        {
            if (mp[r])
            {
                s.insert(mp[r], "(");
                break;
            }
            else
            {
                mp[r] = index;
                r *= 10;
                int q = r / d;
                s += to_string(q);
                r %= d;
                index++;
                if (r == 0)
                    return s;
            }
        }
        s += ")";
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int numerator, denominator;
        cin >> numerator >> denominator;
        Solution ob;
        string ans = ob.fractionToDecimal(numerator, denominator);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends