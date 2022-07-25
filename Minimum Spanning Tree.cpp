//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    typedef pair<int, int> pi;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prim's ALgorithm:
        vector<bool> mst(V, false);
        vector<int> key(V, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        key[0] = 0;
        pq.push({0, 0});
        int ans = 0;
        while (!pq.empty())
        {
            int val = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (mst[u] == true)
                continue;
            mst[u] = true;
            ans += key[u];
            for (auto x : adj[u])
            {
                int v = x[0];
                int wt = x[1];
                if (mst[v] == false && wt < key[v])
                {
                    key[v] = wt;
                    pq.push({key[v], v});
                }
            }
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends