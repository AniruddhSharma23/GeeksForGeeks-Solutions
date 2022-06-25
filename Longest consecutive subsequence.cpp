// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        set<int> s(arr, arr + N);

        int len = 0;
        int k = 0;
        for (int i = 0; i < N; i++)
        {
            int x = arr[i];
            if (s.find(x - 1) == s.end())
            {
                len = 0;
                while (s.find(x + len) != s.end())
                {
                    len++;
                }
                k = max(k, len);
            }
        }
        return k;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends