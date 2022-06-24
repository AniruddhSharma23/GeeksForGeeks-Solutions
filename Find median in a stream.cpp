// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double median = 0.0;
    // Function to insert heap.
    void insertHeap(int &x)
    {
        int m1 = maxheap.size();
        int m2 = minheap.size();
        if (m1 == 0)
        {
            maxheap.push(x);
            median = (double)x;
            return;
        }
        if (m1 > m2)
        {
            int k = maxheap.top();
            if (x < k)
            {
                minheap.push(k);
                maxheap.pop();
                maxheap.push(x);
            }
            else
            {
                minheap.push(x);
            }
            int t1 = maxheap.top();
            int t2 = minheap.top();
            median = (double)((t1 + t2) / 2.0);
        }
        else
        {
            int k = maxheap.top();
            if (x > k)
            {
                minheap.push(x);
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else
            {
                maxheap.push(x);
            }
            median = (double)(maxheap.top());
        }
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
    }

    // Function to return Median.
    double getMedian()
    {
        return median;
    }
};

// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} // } Driver Code Ends