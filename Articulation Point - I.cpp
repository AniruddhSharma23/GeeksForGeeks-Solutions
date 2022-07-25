//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int u, int parent, int &time, vector<int> adj[], vector<bool> &isArticulation, vector<int> &disc, vector<int> &low, vector<bool> &vis)
    {
        vis[u] = true;
        int no_of_child = 0;
        disc[u] = low[u] = time++;
        for (auto v : adj[u])
        {
            if (vis[v] == false)
            {
                no_of_child++;
                dfs(v, u, time, adj, isArticulation, disc, low, vis);
                low[u] = min(low[u], low[v]);
                if (low[v] >= disc[u] && parent != -1)
                    isArticulation[u] = true;
            }
            else if (v != parent)
            {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (parent == -1 && no_of_child > 1)
            isArticulation[u] = true;
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> low(V, -1);
        vector<bool> vis(V, false);
        vector<int> disc(V, -1);
        vector<bool> isArticulation(V, false);
        vector<int> ans;
        int time = 0;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                dfs(i, -1, time, adj, isArticulation, disc, low, vis);
            }
        }
        for (int i = 0; i < V; i++)
            if (isArticulation[i] == true)
                ans.push_back(i);
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends