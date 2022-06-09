// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a)
    {

        // Your code here
        int k = count(a.begin(), a.end(), '1');
        return (k * (k - 1)) / 2;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n, count;
    string a;
    cin >> t;
    while (t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}
// } Driver Code Ends