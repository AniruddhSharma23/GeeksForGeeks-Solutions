// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string removeKdigits(string S, int k)
    {
        int i = 0;
        stack<char> s;
        while (S[i] != '\0')
        {
            while (!s.empty() && s.top() > S[i] && k)
            {
                s.pop();
                k--;
            }
            if (!s.empty() || S[i] != '0')
                s.push(S[i]);
            i++;
        }
        while (!s.empty() && k--)
            s.pop();
        string str = "";
        while (!s.empty())
        {
            str += s.top();
            s.pop();
        }
        reverse(str.begin(), str.end());
        if (str.empty())
            str += "0";
        return str;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends