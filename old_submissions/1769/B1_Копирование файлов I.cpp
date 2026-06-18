#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    double one_proc = sum / 100.0;
    vector<int> ans;
    for (int proc = 0; proc < 101; ++proc)
    {
        bool get_ans = false;
        int l = ceil(one_proc * proc), r = ceil(one_proc * (proc + 1)) - 1;
        int sum1 = 0;
        for (int i = 0; i < n; ++i)
        {
            int ll = ceil(a[i] / 100.0 * proc), rr = ceil(a[i] / 100.0 * (proc + 1)) - 1;
            if (ll <= rr && (sum1 + ll >= l && sum1 + ll <= r || sum1 + rr >= l && sum1 + rr <= r))
            {
                get_ans = true;
            }
            // if (sum1 < l && sum1 + a[i] > r)
            // {
            //     int ll = ceil(a[i] / 100.0 * proc) && 
            //     int now = ceil(a[i] / 100.0 * proc);
            //     if (now + sum1 >= l && now + sum1 <= r && now <= a[i] / 100.0 * (proc + 1))
            //     {
            //         get_ans = true;
            //     }
            //     int now1 = ceil(a[i] / 100.0 * (proc + 1)) - 1;
            //     if (now + sum1 < l && now1 >= l && now1 >= now)
            //     {
            //         get_ans = true;
            //     }
            // }
            // else if (sum1 >= l && sum1 <= r)
            // {
            //     if (ceil(a[i] / 100.0 * proc) <= a[i] / 100.0 * (proc + 1))
            //     {
            //         get_ans = true;
            //     }
            // }
            sum1 += a[i];
        }
        if (get_ans)
        {
            ans.push_back(proc);
        }
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }  
}

/*
19 + 20 + 24 + 28 + 32 + 36 + 37
39 63 91 123 198
*/