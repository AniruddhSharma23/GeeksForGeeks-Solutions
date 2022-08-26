//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string findSum(string x, string y)
    {
        int nx = x.length();
        int ny = y.length();
        int i = nx - 1, j = ny - 1;
        string s = "";
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int a = (i >= 0) ? x[i] - '0' : 0;
            int b = (j >= 0) ? y[j] - '0' : 0;
            int c = a + b + carry;
            carry = c / 10;
            c %= 10;
            s.push_back(c + '0');
            i--;
            j--;
        }
        if (carry != 0)
            s.push_back(carry + '0');
        reverse(s.begin(), s.end());
        i = 0;
        int n = s.length();
        while (i < n && s[i] == '0')
            i++;
        s = s.substr(i);
        if (s == "")
            return "0";
        return s;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends