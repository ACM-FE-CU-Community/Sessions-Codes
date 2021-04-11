// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.

// Problem: https://codeforces.com/group/zvsr84He8w/contest/322905/problem/G

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

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

const int N = 1e5 + 15;
int sm[N];

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  ll n, d;
  cin >> n >> d;
  vector<pair<ll, ll>> a(n);
  vector<ll> b(n);

  for (auto &i :a) cin >> i.first >> i.second;

  sort(all(a));
  for (int i = 1; i < n; ++i) {
    a[i].second += a[i - 1].second;
  }

  ll mx = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    int lst = lower_bound(all(a), make_pair(a[i].first + d, 0LL)) - a.begin() - 1;

    if (i == 0) {
      mx = max(mx, a[lst].second);
    } else {
      mx = max(mx, a[lst].second - a[i - 1].second);
    }
  }

  cout << mx << endl;
}
/*

money friend
4 5
0 100 -> 0
75 1 -> 1 -> i
75 5 -> 2
150 20 -> 3 -> j

     i     j
     |     |
idx: 0 1 2 3
arr: 1 2 3 4
acc: 1 3 6 10

*/
