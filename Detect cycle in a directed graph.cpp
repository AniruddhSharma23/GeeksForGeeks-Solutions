// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &recst, int s)
    {
        vis[s] = 1;
        recst[s] = 1;
        for (auto u : adj[s])
        {
            if (vis[u] == 0)
            {
                if (dfs(adj, vis, recst, u) == true)
                    return true;
            }
            else
            {
                if (recst[u] == 1)
                    return true;
            }
        }
        recst[s] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> recst(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(adj, vis, recst, i) == true)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends