#include <bits/stdc++.h>

using namespace std;

vector <bool> vis;
vector <vector <int>> adj;

void dfs(int cur)
{
    vis[cur] = true;
    for (auto &i : adj[cur]) {
        if (vis[i]) continue;
        dfs(i);
    }
    cout << cur+1 << ' ';
}

int main()
{
    int n, m; cin >> n >> m;
    adj.assign(n, {});
    vis.assign(n, false);
    while(m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    return 0;
}
