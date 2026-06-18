#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int l, r, ans = -1;
    cin >> l >> r;
    for (int i = l; i < r + 1; ++i)
    {
        int temp = i;
        bool flag = true;
        vector<bool> a(10, true);
        while (temp != 0)
        {
            int j = temp % 10;
            temp /= 10;
            if (a[j])
                a[j] = false;
            else
                flag = false;
        }
        if (flag)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
