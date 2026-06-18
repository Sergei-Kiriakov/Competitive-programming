#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int n, k;
    cin >> n >> k;
    set<pair<int, int> > s;
    vector<pair<int, pair<int, int> > > a(2 * n);
    vector<pair<int, int> > b(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[2 * i].first >> a[2 * i + 1].first;
        a[i * 2 + 1].first++;
        b[i].first = a[2 * i].first;
        b[i].second = a[2 * i + 1].first;
        a[2 * i].second.first = 1;
        a[2 * i + 1].second.first = -1;
        a[2 * i].second.second = i;
        a[2 * i + 1].second.second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n; ++i)
    {
        if (a[i].second.first == -1)
        {
            s.erase(make_pair(a[i].first, a[i].second.second));
        }
        else
        {
            if (s.size() == k)
            {
                s.insert(make_pair(b[a[i].second.second].second, a[i].second.second));
                pair<int, int> l;
                l = *s.rbegin();
                ans.push_back(l.second);
                s.erase(l);
            }
            else
            {
                s.insert(make_pair(b[a[i].second.second].second, a[i].second.second));
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] + 1 << " ";
    }
}
