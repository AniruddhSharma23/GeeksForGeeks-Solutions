// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], int u, int p, vector<int> &vis)
    {
        vis[u] = 1;
        for (auto it : adj[u])
        {
            if (vis[it] == 0)
            {
                if (dfs(adj, it, u, vis) == true)
                    return true;
            }
            else
            {
                if (it != p)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(adj, i, -1, vis) == true)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends