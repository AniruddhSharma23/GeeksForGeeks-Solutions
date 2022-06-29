// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string encryptString(string S)
    {
        // code here
        map<int, char> mp;
        mp[0] = '0';
        mp[1] = '1';
        mp[2] = '2';
        mp[3] = '3';
        mp[4] = '4';
        mp[5] = '5';
        mp[6] = '6';
        mp[7] = '7';
        mp[8] = '8';
        mp[9] = '9';
        mp[10] = 'a';
        mp[11] = 'b';
        mp[12] = 'c';
        mp[13] = 'd';
        mp[14] = 'e';
        mp[15] = 'f';
        int k = 1;
        int n = S.length();
        string s = "";
        for (int i = 0; i < n; i++)
        {
            while (S[i] == S[i + 1] && i < n - 1)
            {
                k++;
                i++;
            }
            s += S[i];
            while (k > 0)
            {
                int d = k % 16;
                s += mp[d];
                k = floor(k / 16.0);
            }
            k = 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.encryptString(S) << endl;
    }
    return 0;
} // } Driver Code Ends