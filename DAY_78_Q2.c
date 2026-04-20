#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& vis, vector<int>& disc, vector<int>& low, vector<int>& ap, int& timer) {
        vis[u] = 1;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (auto v : adj[u]) {
            if (v == parent) continue;

            if (!vis[v]) {
                children++;
                dfs(v, u, adj, vis, disc, low, ap, timer);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent == -1 && children > 1)
            ap[u] = 1;
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), disc(V, -1), low(V, -1), ap(V, 0);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, -1, adj, vis, disc, low, ap, timer);
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (ap[i])
                res.push_back(i);
        }

        if (res.empty())
            return {-1};

        sort(res.begin(), res.end());
        return res;
    }
};