#include <bits/stdc++.h>
using namespace std;

class UsingBFS
{
public:
    vector<int> TopoSort(int V, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(V);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> indegree(V, 0);

        for (int node = 0; node < V; node++)
        {
            for (int adjNode : adj[node])
            {
                indegree[adjNode]++;
            }
        }

        queue<int> que;

        for (int node = 0; node < V; node++)
        {
            if (indegree[node] == 0)
            {
                que.push(node);
            }
        }

        vector<int> topo;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            topo.push_back(node);

            for (int adjNode : adj[node])
            {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0)
                {
                    que.push(adjNode);
                }
            }
        }

        return topo;
    }
};

class UsingDFS
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stk)
    {
        vis[node] = 1;

        for (int adjNode : adj[node])
        {
            dfs(adjNode, vis, adj, stk);
        }

        stk.push(node);
    }

public:
    vector<int> TopoSort(int V, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(V);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        stack<int> stk;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, stk);
            }
        }

        vector<int> topo;

        while (!stk.empty())
        {
            topo.push_back(stk.top());
            stk.pop();
        }

        return topo;
    }
};