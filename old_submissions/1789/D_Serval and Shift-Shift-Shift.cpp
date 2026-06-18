#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void move(string &a, int k)
{
    int n = a.size();
    string b = a;
    for (int i = 0; i < n; ++i)
    {
        if (i - k > -1 && i - k < n)
        {
            b[i] = a[i - k];
        }
        else
        {
            b[i] = '0';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        a[i] = ((b[i] - '0') ^ (a[i] - '0')) + '0';
    }
}

void update (string &a, string &b, int &hb_a, int &lb_a, int &hb_b, int &lb_b)
{
    hb_a = -1;
    lb_a = -1;
    hb_b = -1;
    lb_b = -1;
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        if (hb_a == -1 && a[i] == '1')
        {
            hb_a = i;
        }
        if (a[i] == '1')
        {
            lb_a = i;
        }
        if (hb_b == -1 && b[i] == '1')
        {
            hb_b = i;
        }
        if (b[i] == '1')
        {
            lb_b = i;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int hb_a = -1, lb_a = -1, hb_b = -1, lb_b = -1;
    vector<int> ans;
    update(a, b, hb_a, lb_a, hb_b, lb_b);
    if (hb_a == -1 && hb_b != -1 || hb_a != -1 && hb_b == -1)
    {
        cout << -1 << endl;
        return;
    }
    if (hb_a > lb_b)
    {
        ans.push_back(lb_b - hb_a);
        move(a, lb_b - hb_a);
        update(a, b, hb_a, lb_a, hb_b, lb_b);
    }
    for (int i = lb_b + 1; i < n; ++i)
    {
        if (a[i] == '1')
        {
            ans.push_back(i - hb_a);
            move(a, i - hb_a);
            update(a, b, hb_a, lb_a, hb_b, lb_b);
        }
    }
    // update(a, b, hb_a, lb_a, hb_b, lb_b);
    if (lb_a < lb_b)
    {
        ans.push_back(lb_b - lb_a);
        move(a, lb_b - lb_a);
        update(a, b, hb_a, lb_a, hb_b, lb_b);
    }
    for (int i = lb_b - 1; i > -1; --i)
    {
        if (a[i] != b[i])
        {
            ans.push_back(i - lb_a);
            move(a, i - lb_a);
            update(a, b, hb_a, lb_a, hb_b, lb_b);
        }
    }
    cout << ans.size() << endl;
    if (ans.size())
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << -ans[i] << " ";
        }
        cout << endl;
    }
    // cout << a << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}

/*
1
2
11
10
*/