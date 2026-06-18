#include <bits/stdc++.h>
using namespace std;
int main() {
// если мы можем достичь чётной точки за нечётное число векторов, то "No"
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<bitset<1515>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            a[i][j] = x & 1;
        }
        a[i][k] = 1;
    }
    for (int col = 0, rank = 0; rank < n && col < k; col++) {
        if (!a[rank][col])
            for (int row = rank+1; row < n; row++)
                if (a[row][col]) {
                    swap(a[rank], a[row]);
                    break;
                }
        if (!a[rank][col])
            continue;
        for (int row = rank+1; row < n; row++)
            if (a[row][col])
                a[row] ^= a[rank];
        rank += (a[rank][col] == 1);
    }
    bool ok = 1;
    for (int i = 0; i < n; i++)
        ok &= !(a[i]._Find_first() == k);
    cout << (ok ? "Yes\n" : "No\n");
}