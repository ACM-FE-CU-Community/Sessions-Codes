#include <bits/stdc++.h>

using namespace std;

int a[5];

bool solve(int idx, int ans) {
    if (idx == 5) {
        return ans == 23;
    }
    
    return solve(idx + 1, ans * a[idx]) ||
           solve(idx + 1, ans + a[idx]) ||
           solve(idx + 1, ans - a[idx]);
}

int main() {
    while(1) {
        int cntZeros = 0;
        for (int i = 0; i < 5; i++) {
            cin >> a[i];
        }

        if (a[0] == 0) 
            break;  

        sort(a, a + 5);
        bool possible = false;

        do {
            possible = solve(1, a[0]);
            
            if (possible) {
                cout << "Possible\n";
                break;
            }
            
        } while (next_permutation(a, a + 5));
            
        if (!possible)
            cout  << "Impossible\n";
    }
}