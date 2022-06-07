// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to remove pair of duplicates from given string using Stack.
    string removePair(string s)
    {
        // Your code here
        int n = s.length();
        stack<char> st;
        string k = "";
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (st.top() == s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        while (!st.empty())
        {
            k += st.top();
            st.pop();
        }
        reverse(k.begin(), k.end());
        return k;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        string ans = obj.removePair(s);
        if (ans == "")
            cout << "Empty String" << endl;
        else
            cout << ans << endl;
    }

    return 0;
} // } Driver Code Ends