class Solution
{
public:
    bool checkBipartiteBFS(vector<vector<int>> &graph, vector<int> &color, int node)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            for (auto it : graph[ele])
            {
                if (color[it] == -1)
                {
                    q.push(it);
                    color[it] = 1 - color[ele];
                }
                else if (color[it] == color[ele])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == -1)
            {
                if (!checkBipartiteBFS(graph, color, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};