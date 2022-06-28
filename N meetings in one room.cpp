// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    typedef pair<int, int> pi;
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pi> v;
        for (int i = 0; i < n; i++)
            v.push_back(make_pair(start[i], end[i]));
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a.second < b.second; });
        int k = 1;
        int p = 0;
        for (int i = 1; i < v.size(); i++)
        {
            auto x = v[i];
            auto q = v[p];
            if (x.first > q.second)
            {
                k++;
                p = i;
            }
        }
        return k;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends