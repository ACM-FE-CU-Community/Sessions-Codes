//
// Created by Dandosh on --/2/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

/*
    Link: https://codeforces.com/problemset/problem/580/B
*/

int main()
{
    IO;
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, d;
    cin >> n >> d;
    vector<pair<int, ll>> persons(n);
    for (int i = 0; i < n; i++)
        cin >> persons[i].first >> persons[i].second;

    sort(persons.begin(), persons.end());
    for (int i = 1; i < n; i++) // cum sum over friendship factor
        persons[i].second += persons[i - 1].second;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        // get the farthest one I can take with me
        auto it = lower_bound(persons.begin(), persons.end(), make_pair(persons[i].first + d, 0LL));
        ll limit = it - persons.begin() - 1;

        ans = max(ans, persons[limit].second - (i ? persons[i - 1].second : 0));
    }

    cout << ans << endl;
    return 0;
}