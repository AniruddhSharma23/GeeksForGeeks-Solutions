//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    bool dfs(int u, int parent, int &time, vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<int> adj[])
    {
        vis[u] = true;
        time++;
        disc[u] = low[u] = time;
        for (auto v : adj[u])
        {
            if (vis[v] == false)
            {
                dfs(v, u, time, disc, low, vis, adj);
                low[u] = min(low[u], low[v]);
            }
            else if (v != parent)
                low[u] = min(low[u], disc[v]);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> vis(V, false);
        int time = 0;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
                dfs(i, -1, time, disc, low, vis, adj);
        }
        if (low[d] > disc[c] || low[c] > disc[d])
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends