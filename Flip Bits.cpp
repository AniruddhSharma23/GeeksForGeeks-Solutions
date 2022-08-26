//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        for (int i = 0; i < n; i++)
            a[i] = (a[i] == 0) ? 1 : -1;
        bool check = false;
        for (int i = 0; i < n; i++)
            if (a[i] == 1)
            {
                check = true;
                break;
            }
        if (check == false)
            return n;
        int curr = 0;
        int mx = 0;
        int l = 0, r = 0;
        vector<int> v(2);
        for (int i = 0; i < n; i++)
        {
            curr += a[i];
            if (curr > mx)
            {
                mx = curr;
                r = i;
                v[0] = l;
                v[1] = r;
            }
            if (curr < 0)
            {
                curr = 0;
                l = i + 1;
            }
        }
        for (int i = v[0]; i <= v[1]; i++)
            a[i] *= -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == -1)
                ans++;
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
        int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxOnes(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends