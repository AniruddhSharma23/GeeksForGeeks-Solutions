//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSteps(int n)
    {
        n = abs(n);
        int i = 1, s = 0;
        while (s < n)
            s += i++;
        int d = s - n;
        int step = i - 1;
        if (d == 0 || d % 2 == 0)
            return step;
        if (step % 2 == 0)
            return step + 1;
        return step + 2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
}
// } Driver Code Ends