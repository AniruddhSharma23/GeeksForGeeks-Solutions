// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution
{
public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        // Your code here
        unordered_map<int, int> mp;
        int l = 0;
        int s = 0;
        for (int i = 0; i < N; i++)
        {

            (arr[i] == 0) ? s-- : s++;
            if (s == 0)
                l = max(l, i + 1);
            else
            {
                if (mp.find(s) != mp.end())
                    l = max(l, i - mp[s]);
                else
                    mp[s] = i;
            }
        }
        return l;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends