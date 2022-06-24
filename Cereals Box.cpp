// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long minSum(vector<int> a, int N, int k)
    {
        // code here
        float sum = 0;
        priority_queue<float> pq;
        for (int i = 0; i < N; i++)
        {
            pq.push(a[i]);
        }
        for (int i = 0; i < N; i++)
        {
            float t = pq.top();
            pq.pop();
            if (t < k)
                t = 0;
            else
            {
                float m = t * 0.1;
                (m < k) ? t -= k : t -= m;
                pq.push(t);
            }
        }
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return (long long)sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.minSum(a, N, K) << endl;
    }
    return 0;
} // } Driver Code Ends