#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs1(int u, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v])
                dfs1(v, adj, vis, st);
        }
        st.push(u);
    }

    void dfs2(int u, vector<vector<int>>& rev, vector<int>& vis) {
        vis[u] = 1;
        for (int v : rev[u]) {
            if (!vis[v])
                dfs2(v, rev, vis);
        }
    }

    int kosaraju(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V), rev(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            rev[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs1(i, adj, vis, st);
        }

        fill(vis.begin(), vis.end(), 0);

        int count = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (!vis[u]) {
                dfs2(u, rev, vis);
                count++;
            }
        }

        return count;
    }
};