// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(string s, string ans, vector<string> &v)
    {
        if (s.empty())
        {
            v.push_back(ans);
            return;
        }
        ans.push_back(' ');
        ans.push_back(s[0]);
        solve(s.substr(1), ans, v);

        // backtrack

        ans.pop_back();
        ans.pop_back();
        ans.push_back(s[0]);
        solve(s.substr(1), ans, v);
    }
    vector<string> permutation(string S)
    {
        // Code Here
        string ans = "";
        vector<string> v;
        ans.push_back(S[0]);
        solve(S.substr(1), ans, v);
        return v;
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
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}
// } Driver Code Ends