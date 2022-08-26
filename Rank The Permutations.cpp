//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    const int mod = 1000003;
    int fact(int n)
    {
        if (n <= 1)
            return 1;
        return (n * fact(n - 1) % mod) % mod;
    }
    int calc(string s, int i, int j)
    {
        int count = 0;
        int l;
        for (l = i + 1; l <= j; l++)
        {
            if (s[i] > s[l])
                ++count;
        }
        return count;
    }
    bool check(string s)
    {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (auto &x : mp)
            if (x.second > 1)
                return true;
        return false;
    }
    int rank(string s)
    {
        if (check(s) == true)
            return 0;
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int f = fact(n - i - 1);
            int k = calc(s, i, n - 1) % mod;
            ans = (ans + (k * f) % mod) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.rank(S) << endl;
    }
    return 0;
}
// } Driver Code Ends