// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        // Your code here
        if (s1 == "0" || s2 == "0")
        {
            return "0";
        }
        int neg = 0;
        if (s1[0] == '-' && s2[0] != '-')
        {
            neg = 1;
            s1.erase(s1.begin() + 0);
        }
        else if (s2[0] == '-' && s1[0] != '-')
        {
            neg = 2;
            s2.erase(s2.begin() + 0);
        }
        else if (s2[0] == '-' && s1[0] == '-')
        {
            s1.erase(s1.begin() + 0);
            s2.erase(s2.begin() + 0);
        }

        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> v(n1 + n2);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                int k = (s1[i] - '0') * (s2[j] - '0');
                v[i + j] += k;
                v[i + j + 1] += v[i + j] / 10;
                v[i + j] %= 10;
            }
        }
        reverse(v.begin(), v.end());
        int z = 0;
        while (z < v.size() && v[z] == 0)
        {
            z++;
        }
        string s = "";
        if (neg != 0)
        {
            s = s + '-';
        }
        for (int i = z; i < v.size(); i++)
        {
            s = s + to_string(v[i]);
        }
        return s;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }

} // } Driver Code Ends