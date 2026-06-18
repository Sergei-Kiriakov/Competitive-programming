#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> a(n);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            m += a[i] - (max(a[i + 1] - k, 0));
            if (m < 0)
                flag = false;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
