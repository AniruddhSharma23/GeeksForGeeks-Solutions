//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string makePalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
            s[j--] = s[i++];
        return s;
    }
    string solve(string s)
    {
        int n = s.length();
        string k = makePalindrome(s);
        if (k > s)
            return k;
        int carry = 1;
        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            int t = s[i] - '0' + carry;
            if (t == 10)
                t = 0;
            else
                carry = 0;
            s[i] = '0' + t;
        }
        string s1;
        if (carry == 1)
            s1 = "1";
        s1 += s;
        return makePalindrome(s1);
    }
    vector<int> generateNextPalindrome(int num[], int n)
    {
        string s;
        for (int i = 0; i < n; i++)
            s += num[i] + '0';
        string k = solve(s);
        vector<int> ans;
        for (char c : k)
            ans.push_back(c - '0');
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
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends