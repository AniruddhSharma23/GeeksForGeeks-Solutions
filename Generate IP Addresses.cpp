//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    bool isValid(string s)
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
    void solve(vector<string> &ans, int i, int n, int cnt, string curr, string s)
    {
        if (cnt > 4)
            return;
        if (i == n && cnt == 4)
        {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        string z = curr;
        for (int j = i; j < min(i + 3, n); j++)
        {
            string p = s.substr(i, j - i + 1);
            if (isValid(p))
            {
                z += p + '.';
                solve(ans, j + 1, n, cnt + 1, z, s);
                z = curr;
            }
            else
                break;
        }
    }
    vector<string> genIp(string &s)
    {
        int n = s.length();
        vector<string> ans;
        solve(ans, 0, n, 0, "", s);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (auto &u : str)
            {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends