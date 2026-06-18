#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int n, q;
    cin >> n;
    vector<int> a(n), pr;
    vector<vector<int> > a1(n, vector<int> (2)), e;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a1[i][0] = a[i];
        a1[i][1] = 0;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int b;
        cin >> b;
        if (b == 1) {
            int p, x;
            cin >> p >> x;
            a1[p - 1][0] = x;
            a1[p - 1][1] = i + 10;
        }
        else {
            int x;
            cin >> x;
            vector<int> temp;
            temp.push_back(i + 10);
            temp.push_back(x);
            e.push_back(temp);
        }
    }
    if (e.size() == 0) {
        for (int i = 0; i < n; i++)
        cout << a1[i][0] << " ";
    }
    else {
        pr.push_back(-1);
        for (int i = 0; i < e.size(); i++)
            pr.push_back(max(pr[i], e[e.size() - i - 1][1]));
        reverse(pr.begin(), pr.end());
        for (int i = 0; i < n; i++) {
            int ind = a1[i][1], r = e.size(), l = -1;
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (e[m][0] >= ind)
                    r = m;
                else
                    l = m;
            }
            a1[i][0] = max(pr[r], a1[i][0]);
        }
        for (int i = 0; i < n; i++)
            cout << a1[i][0] << " ";
    }
}
