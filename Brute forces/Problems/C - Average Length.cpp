// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
// Problem link: https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const ll OO = 1e18;
const int oo = INT_MAX;
const double EPS = 1e-9;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

ld distance(ld x1, ld y1, ld x2, ld y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}


int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &i : a) cin >> i.first >> i.second;

  ld fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }

  ld ret = 0.0;
  sort(all(a));
  do {
    for (int i = 0; i < n - 1; i++) {
      ret += distance(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
    }

  } while (next_permutation(all(a)));
  cout << fixed << setprecision(8) << ret / fact << endl;
}
