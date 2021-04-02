// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
// Problem link: https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO \
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
  return hypot(fabs(x1 - x2), fabs(y1 - y2));
}

int main() {
  IO;
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &i : a) cin >> i.first >> i.second;

  int noOfCombinations = 1;
  for (int i = 1; i <= n; i++) {
    noOfCombinations *= i;
  }

  double sum = 0.0;
  sort(all(a));

  do {
    for (int i = 0; i < n - 1; i++) {
      sum += distance(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
    }

  } while (next_permutation(all(a)));

  /*
   * Average = Sum / noOfCombinations
   */
  cout << fixed << setprecision(8) << sum / noOfCombinations << endl;
}
