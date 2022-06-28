// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    typedef pair<int, double> pi;
    typedef double db;
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pi> v;
        db ans = 0.0;
        for (int i = 0; i < n; i++)
        {
            double f = (db)((db)arr[i].value / (db)arr[i].weight);
            v.push_back(make_pair(i, f));
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a.second > b.second; });
        for (int i = 0; i < v.size(); i++)
        {
            db f = v[i].second;
            db wt = arr[v[i].first].weight;
            db val = arr[v[i].first].value;
            if (wt <= W)
            {
                ans += val;
                W -= wt;
            }
            else
            {
                ans += (db)(f * W);
                return ans;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends