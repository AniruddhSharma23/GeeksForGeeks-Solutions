// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> permute(vector<vector<int>> &arr, int n);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }

        vector<int> ans;
        ans = permute(arr, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << "\n";
    }

    return 0;
} // } Driver Code Ends

vector<int> permute(vector<vector<int>> &arr, int n)
{

    // Complete the function
    typedef pair<int, int> pi;
    vector<int> v;
    vector<pi> k;
    for (int i = 0; i < n; i++)
        k.push_back(make_pair(arr[i][0] + arr[i][1], i));
    sort(k.begin(), k.end());
    for (auto x : k)
        v.push_back(x.second + 1);
    return v;
}