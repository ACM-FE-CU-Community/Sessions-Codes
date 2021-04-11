//
// Created by Dandosh on --/2/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

// Link: https://codeforces.com/problemset/problem/253/B

int main()
{
    IO;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int limit = upper_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();

        ans = max(ans, limit - i);
    }

    cout << n - ans << endl;
    return 0;
}