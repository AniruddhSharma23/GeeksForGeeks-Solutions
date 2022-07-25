//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.

    void dfs(vector<int> adj[], int u, vector<bool> &vis, stack<int> &st)
    {
        vis[u] = true;
        for (auto v : adj[u])
            if (vis[v] == false)
                dfs(adj, v, vis, st);
        st.push(u);
    }
    void dfs1(vector<int> rev_adj[], int u, vector<bool> &vis)
    {
        vis[u] = true;
        for (auto v : rev_adj[u])
            if (vis[v] == false)
                dfs1(rev_adj, v, vis);
    }
    int kosaraju(int V, vector<int> adj[])
    {
        // code here
        stack<int> st;
        vector<bool> vis(V, false);
        vector<int> rev_adj[V];

        // step 1:

        for (int i = 0; i < V; i++)
            if (vis[i] == false)
                dfs(adj, i, vis, st);

        // step 2:

        for (int u = 0; u < V; u++)
            for (auto v : adj[u])
                rev_adj[v].push_back(u);

        // step 3:

        fill(vis.begin(), vis.end(), false);
        int ans = 0;
        while (!st.empty())
        {
            int i = st.top();
            st.pop();
            if (vis[i] == true)
                continue;
            ans++;
            dfs1(rev_adj, i, vis);
        }
        return ans;
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

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends