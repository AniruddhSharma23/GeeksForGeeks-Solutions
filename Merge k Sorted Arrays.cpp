// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        // code here
        typedef pair<int, pair<int, int>> pi;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (int i = 0; i < k; i++)
        {
            int r = i;
            int c = 0;
            pq.push(make_pair(arr[r][c], make_pair(r, c)));
        }
        vector<int> v;
        while (!pq.empty())
        {
            pair<int, pair<int, int>> p = pq.top();
            v.push_back(p.first);
            pq.pop();
            int row = p.second.first;
            int col = p.second.second;
            if (col + 1 < arr[0].size())
            {
                pq.push(make_pair(arr[row][col + 1], make_pair(row, col + 1)));
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends