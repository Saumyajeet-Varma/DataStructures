#include <bits/stdc++.h>
using namespace std;

class undirectedAdjacencyList
{
public:
    vector<vector<int>> unweightedAdjacencyList(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(v + 1);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    vector<vector<pair<int, int>>> weightedAdjacencyList(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<pair<int, int>>> adj(v + 1);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return adj;
    }
};

class directedAdjacencyList
{
public:
    vector<vector<int>> unweightedAdjacencyList(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(v + 1);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        return adj;
    }

    vector<vector<pair<int, int>>> weightedAdjacencyList(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<pair<int, int>>> adj(v + 1);

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        return adj;
    }
};
