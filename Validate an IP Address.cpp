//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    bool isSafe(string s)
    {
        int n = s.length();
        if (n == 1 && s[0] == '0')
            return true;
        if (s[0] == '0' || n > 3)
            return false;
        int k = stoi(s);
        if (k >= 0 && k <= 255)
            return true;
        return false;
    }
    int isValid(string s)
    {
        int n = s.length();
        if (n > 15 || n < 7)
            return 0;
        int d = 0;
        if (s[0] == '.' || s[n - 1] == '.')
            return 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '.' && s[i + 1] == '.')
                return 0;
            if (s[i] == '.')
                d++;
        }
        if (d != 3)
            return 0;
        string k = "";
        for (int i = 0; i < n; i++)
        {
            while (i < n && s[i] != '.')
            {
                if (s[i] < '0' || s[i] > '9')
                    return 0;
                k += s[i++];
            }
            if (isSafe(k) == false)
                return 0;
            k = "";
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends