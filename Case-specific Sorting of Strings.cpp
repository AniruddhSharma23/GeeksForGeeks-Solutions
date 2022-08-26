//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string caseSort(string str, int n)
    {
        vector<char> l;
        vector<char> u;
        for (char c : str)
        {
            if (isupper(c))
                u.push_back(c);
            else
                l.push_back(c);
        }
        sort(l.begin(), l.end());
        sort(u.begin(), u.end());
        string ans = "";
        int i1 = 0, i2 = 0;
        for (char c : str)
        {
            if (isupper(c))
                ans += u[i1++];
            else
                ans += l[i2++];
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
        int n;
        cin >> n;
        string str;
        cin >> str;
        Solution obj;
        cout << obj.caseSort(str, n) << endl;
    }
}
// } Driver Code Ends