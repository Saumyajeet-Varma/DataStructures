#include <bits/stdc++.h>
using namespace std;

class undirectedAdjacencyMatrix
{
public:
    vector<vector<int>> unweightedAdjacencyMatrix(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        return adj;
    }

    vector<vector<int>> weightedAdjacencyMatrix(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u][v] = w;
            adj[v][u] = w;
        }

        return adj;
    }
};

class directedAdjacencyMatrix
{
public:
    vector<vector<int>> unweightedAdjacencyMatrix(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u][v] = 1;
        }

        return adj;
    }

    vector<vector<int>> weightedAdjacencyMatrix(int v, int e, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u][v] = w;
        }

        return adj;
    }
};