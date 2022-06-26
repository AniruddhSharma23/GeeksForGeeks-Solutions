// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution
{

public:
    int calc(int n)
    {
        int k = 0;
        while (n > 0)
        {
            k += n % 10;
            n /= 10;
        }
        return k;
    }
    int RulingPair(vector<int> arr, int n)
    {
        // Your code goes here
        unordered_map<int, priority_queue<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int k = calc(arr[i]);

            if (mp[k].size() == 2)
            {
                int a = mp[k].top();
                mp[k].pop();
                int b = mp[k].top();
                mp[k].pop();
                mp[k].push(a);
                mp[k].push(max(b, arr[i]));
            }
            else
            {
                mp[k].push(arr[i]);
            }
        }
        int m = -1;
        for (auto x : mp)
        {
            if (x.second.size() == 2)
            {
                int a = x.second.top();
                x.second.pop();
                int b = x.second.top();
                x.second.pop();
                m = max(m, a + b);
            }
        }
        return m;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.RulingPair(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends