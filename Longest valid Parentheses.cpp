// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxLength(string S)
    {
        // code here
        int n = S.length();
        stack<int> st;
        st.push(-1);
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int p = st.size();
            if (S[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    int k = i - st.top();
                    m = max(m, k);
                }
            }
        }
        return m;
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

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
} // } Driver Code Ends