#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

void solveJ(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<tuple<int, int, int>>> edges(n);
  
  for (int i = 0; i < m; ++i){
    int u, v, s, w;
    cin >> u >> v >> s >> w;
    --u;
    --v;
    edges[u].emplace_back(v, s, w);
  }
  
  vector<tuple<int, int, int>> days;
  for (int i = 0; i < q; ++i){
    int a, b;
    cin >> a >> b;
    days.emplace_back(a, b, i);
  }
  
  sort(days.begin(), days.end(), 
    [](tuple<int, int, int> f, tuple<int, int, int> s){
      int a1 = get<0>(f), b1 = get<1>(f);
      int a2 = get<0>(s), b2 = get<1>(s);
      return a1 * b2 < a2 * b1;
    });

  vector<bool> used(n, false);
  
  // function<bool(int, double)> dfs = [&](int v, double trashold){
  //   if (v == n - 1) 
  //     return true;
  //   used[v] = true;
    
  //   for (auto [nxt, s, w] : edges[v]){
  //     if (used[nxt]) 
  //       continue;
  //     if (trashold * double(s) > double(w))
  //       if (dfs(nxt, trashold)) 
  //         return true;
  //   }
  //   return false;
  // };
  function<bool(int, int, int)> dfs = [&](int v, int tra, int trb){
    if (v == n - 1) 
      return true;
    used[v] = true;
    
    for (auto [nxt, s, w] : edges[v]){
      if (used[nxt]) 
        continue;
      if (tra * s > trb * w)
        if (dfs(nxt, tra, trb)) 
          return true;
    }
    return false;
  };
  
  int l = -1, r = q;
  while (r - l > 1){
    int mid = (l + r) >> 1;
    int a = get<0>(days[mid]), b = get<1>(days[mid]);

    fill(used.begin(), used.end(), false);
    
    if (dfs(0, a, b)) 
      r = mid;
    else 
      l = mid;
  }
  // int a = get<0>(days[l]), b = get<1>(days[l]);
  // if (dfs(0, a, b))
  //   --l;
  
  vector<bool> ans(q);
  for (int i = 0; i < q; ++i){
    auto [a, b, index] = days[i];
    if (i <= l) 
      ans[index] = false;
    else 
      ans[index] = true;
  }
  
  for (bool i : ans) 
    if (i) 
      cout << "YES\n"; 
    else 
      cout << "NO\n";
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solveJ();
    }
}


/*
*/