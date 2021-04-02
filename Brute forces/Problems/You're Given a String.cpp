//
// Created by Dandosh on --/2/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int main() {
  IO;
  string s;
  cin >> s;
  int n = s.size(), ans = 0;

  for (int i = 0; i < n; i++) {
    string t;
    for (int j = i; j < n; j++) {
      t += s[j];

      int firstPos = -1, lastPos = -1;
      for (int k = 0; k + t.size() <= n; k++)
        if (s.substr(k, t.size()) == t) {
          if (firstPos == -1) firstPos = k;
          lastPos = k;
        }

      if (firstPos != lastPos) ans = max(ans, (int)t.size());
    }
  }

  cout << ans << endl;
  return 0;
}
