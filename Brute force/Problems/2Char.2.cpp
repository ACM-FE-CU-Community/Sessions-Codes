//
// Created by Dandosh on --/2/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int main()
{
    IO;
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, ans = 0;
    string s;
    cin >> n;

    map<pair<char, char>, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        set<char> st;
        for (auto j : s)
            st.insert(j);

        if (st.size() <= 2)
        {
            char c1 = *st.begin();
            char c2 = *(--st.end());

            freq[{c1, c2}] += s.length();
        }
    }

    for (char i = 'a'; i <= 'z'; i++)
        for (char j = 'a'; j <= 'z'; j++)
            if (i != j)
                ans = max(ans, freq[{i, j}] + freq[{i, i}] + freq[{j, j}]);
            else
                ans = max(ans, freq[{i, j}]);

    cout << ans << endl;
    return 0;
}