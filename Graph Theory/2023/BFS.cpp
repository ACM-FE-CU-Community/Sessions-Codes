#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m; cin >> n >> m;
    vector <bool> vis(n, false);
    vector <vector <int>> adj(n);
    while(m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
/*    queue <int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur+1 << ' ';
        for (auto &i : adj[cur]) {
            if (!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }*/
    vector <int> dist(n, -1);
    dist[0] = 0;
    queue <int> q;
    q.push(0);
    vector <int> par(n, -1);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (!~dist[i]) { // dist[i] == -1
                q.push(i);
                par[i] = cur;
                dist[i] = dist[cur]+1;
            }
        }
    }
    cout << dist[n-1]+1 << '\n';
    vector <int> path;
    int cur = n-1;
    while(~cur) { // cur != -1
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    for (auto &i : path) cout << i+1 << ' ';
    cout << '\n';
    return 0;
}
