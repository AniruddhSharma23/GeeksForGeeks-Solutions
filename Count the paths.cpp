// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> adj[15];
    void dfs(vector<int> adj[], int s, int n, int &k, int &d)
    {
        if (s == d)
        {
            k++;
            return;
        }
        else
        {
            for (auto it : adj[s])
                dfs(adj, it, n, k, d);
        }
    }
    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        // Code here
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        int k = 0;
        dfs(adj, s, n, k, d);
        return k;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends