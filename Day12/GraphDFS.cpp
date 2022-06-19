// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void d(int i, vector<bool> &vis, vector<int> adj[], vector<int> &dfs)
    {
        dfs.push_back(i);
        vis[i] = true;
        for (auto it : adj[i])
        {
            if (vis[it] == false)
            {
                d(it, vis, adj, dfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> dfs;
        vector<bool> visited(V + 1, false);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                d(i, visited, adj, dfs);
            }
        }
        return dfs;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends