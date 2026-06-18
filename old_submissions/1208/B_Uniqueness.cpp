#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a;

bool check(int m, int n) {
    for (int i = 0; i < n; i++) {
        vector<int> b;
        for (int j = 0; j < n; j++) {
            if (j < i || j >= i + m) {
                b.push_back(a[j]);
            }
        }
        sort(b.begin(), b.end());
        bool flag = true;
        for (int j = 1; j < b.size(); j++) {
            if (b[j - 1] == b[j])
                flag = false;
        }
        if (flag)
            return true;
    }
    return false;
}

int32_t main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = -1, r = n;
    while (r - l != 1) {
        int m = (r + l) / 2;
        if (check(m, n)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r;
}
