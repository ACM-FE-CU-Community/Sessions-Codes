#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector <vector <int>> adj_list(n);
//    vector <bitset<101>> adj_mat(n);
    vector <vector <bool>> adj_mat(n, vector <bool> (n, false));
    while(m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        adj_mat[u][v] = true;
        adj_mat[v][u] = true;
    }
    return 0;
}
