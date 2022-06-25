// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; i++)
        {
            int s = 0;
            for (int j = i; j < N; j++)
            {
                s += Arr[j];
                if (pq.size() < k)
                    pq.push(s);
                else
                {
                    if (pq.top() < s)
                    {
                        pq.pop();
                        pq.push(s);
                    }
                }
            }
        }
        return pq.top();
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends