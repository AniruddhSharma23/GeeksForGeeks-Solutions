// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
The structure to use is as follows
struct val{
    int first;
    int second;
};*/

/*You are required to complete this method*/
bool compare(val a, val b)
{
    return a.first < b.first;
}
int maxChainLen(struct val p[], int n)
{
    // Your code here
    sort(p, p + n, compare);
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[j].second < p[i].first)
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    return *max_element(lis.begin(), lis.end());
}