#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int V)
    {
        parent.resize(V);
        size.resize(V, 1);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
        {
            return;
        }

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += pu;
        }
    }
};

class MST
{
public:
    int primsAlgorithm(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        int mst = 0;

        pq.push({0, 0});

        while (!pq.empty())
        {
            pair<int, int> topp = pq.top();
            pq.pop();

            int wt = topp.first;
            int node = topp.second;

            if (vis[node])
            {
                continue;
            }

            vis[node] = 1;
            mst += wt;

            for (vector<int> it : adj[node])
            {
                int adjNode = it[0];
                int weight = it[1];

                if (!vis[adjNode])
                {
                    pq.push({weight, adjNode});
                }
            }
        }

        return mst;
    }

    int kruskalsAlgorithm(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        for (int node = 0; node < V; node++)
        {
            for (vector<int> it : adj[node])
            {
                int adjNode = it[0];
                int weight = it[1];

                edges.push_back({weight, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        int mst = 0;

        for (pair<int, pair<int, int>> edge : edges)
        {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findParent(u) != ds.findParent(v))
            {
                mst += w;
                ds.unionBySize(u, v);
            }
        }

        return mst;
    }
};