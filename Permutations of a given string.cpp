// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(int i, int n, string s, vector<string> &ans, set<string> &st)
    {
        if (i == n)
        {
            if (st.find(s) == st.end())
            {
                ans.push_back(s);
                st.insert(s);
            }
            return;
        }
        for (int j = i; j < n; j++)
        {
            swap(s[i], s[j]);
            solve(i + 1, n, s, ans, st);
            swap(s[i], s[j]);
        }
    }
    vector<string> find_permutation(string S)
    {
        // Code here there
        int n = S.length();
        vector<string> ans;
        set<string> st;
        solve(0, n, S, ans, st);
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends