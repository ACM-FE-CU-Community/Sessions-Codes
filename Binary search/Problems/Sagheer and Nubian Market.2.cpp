//
// Created by Dandosh on --/2/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int n, s, arr[MAXN];

pair<bool, ll> ok(int noOfSouvs)
{
    vector<ll> newValues(n);
    for (int i = 0; i < n; i++)
        newValues[i] = arr[i] + noOfSouvs * (i + 1LL);

    ll sum = 0;
    sort(newValues.begin(), newValues.end());
    for (int i = 0; i < noOfSouvs; i++)
        sum += newValues[i];

    return {sum <= s, sum};
}

int main()
{
    IO;
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0, r = n, mid, noOfSouvs = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (ok(mid).first)
        {
            l = mid + 1;
            noOfSouvs = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << noOfSouvs << ' ' << ok(noOfSouvs).second << endl;
    return 0;
}