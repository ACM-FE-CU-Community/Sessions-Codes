#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int N = 1e5 + 5;
int need[N], have[N];
int n, k;

bool ok(int noOfCakes) {
    ll magicPowder = k;

    for (int i = 0; i < n; i++) {
        ll extraNeed = (ll) need[i] * noOfCakes - have[i];

        if (extraNeed < 0) // we have enough
            continue;

        magicPowder -= extraNeed; // remove the extra need from the magic powder
        if (magicPowder < 0) // magic powder isn't enough
            return false;
    }
    return true;
}

int main() {
    IO;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> need[i];
    for (int i = 0; i < n; i++)
        cin >> have[i];

    int res = 0;
    for (int i = 0; i <= 2000; i++) {
        if (!ok(i)) {
            break;
        }

        res = i;
    }

    cout << res << endl;
    return 0;
}