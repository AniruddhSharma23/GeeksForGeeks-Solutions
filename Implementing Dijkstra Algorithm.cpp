//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    typedef pair<int, int> pi;
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<bool> finalized(V, false);               // to check if a vertex is finalized or not
        priority_queue<pi, vector<pi>, greater<pi>> pq; // to store pair of {dist,vertex}
        vector<int> dist(V, INT_MAX);                   // final distance array
        pq.push({0, S});                                // push the source
        dist[S] = 0;
        while (!pq.empty())
        {
            int vertex = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            if (finalized[vertex] == false)
                finalized[vertex] = true;
            else // if it is already finalized then move to the next vertex
                continue;
            for (auto x : adj[vertex])
            {
                int adj_vertex = x[0];
                int weight = x[1];
                int new_dist = distance + weight;
                if (new_dist < dist[adj_vertex])
                {
                    pq.push({new_dist, adj_vertex});
                    dist[adj_vertex] = new_dist;
                }
            }
        }
        return dist;
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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends