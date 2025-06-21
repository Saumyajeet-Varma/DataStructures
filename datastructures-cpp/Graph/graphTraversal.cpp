#include <bits/stdc++.h>
using namespace std;

class graphBFS
{
public:
    vector<int> bfs(int v, vector<vector<int>> adj)
    {
        vector<int> res;
        vector<int> vis(v, 0);
        queue<int> que;

        que.push(0);
        vis[0] = 1;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            res.push_back(node);

            for (int nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    que.push(nbr);
                    vis[nbr] = 1;
                }
            }
        }

        return res;
    }
};

class graphDFS
{
private:
    void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> res)
    {
        res.push_back(node);
        vis[node] = 1;

        for (int nbr : adj[node])
        {
            if (!vis[nbr])
                dfsHelper(nbr, adj, vis, res);
        }
    }

public:
    vector<int> dfs(int v, vector<vector<int>> adj)
    {
        vector<int> res;
        vector<int> vis(v, 0);

        dfsHelper(0, adj, vis, res);

        return res;
    }
};