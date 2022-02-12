#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    if (n == 1) 
        return 1;

    if (n % 2 == 0) 
        return 1 + solve(n / 2);

    return 1 + solve(3 * n + 1);
}

int main() {
    int a, b;
    while(cin >> a >> b) {
        int maxi = 0;
        for (int i = min(a, b); i <= max(a, b); i++) {
            maxi = max(maxi, solve(i));
        }

        cout << a << ' ' << b << ' ' << maxi << endl;
    }    
}