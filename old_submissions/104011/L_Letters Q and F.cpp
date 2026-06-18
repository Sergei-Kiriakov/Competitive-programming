#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

const int mod = 1e9 + 7;

void solve()
{
  int n, m, c;
  cin >> n >> m >> c;
  int ans = 1e18, ans1 = -1, ans2 = -1;
  for (int i = 0; i < n / m; ++i)
    {
      int d = n - m * i;
      if (d % c == 0 && d >= 0)
      {
        int j = d / c;
        if (abs(i * m + c * j - n) < ans)
        {
          ans = abs(i * m + c * j - n);
          ans1 = i;
          ans2 = j;
        }
      }
    }
  cout << ans1 << " " << ans2 << endl;
}

void solveL(){
  int n, m;
  cin >> n >> m;
  vector<string> field(n);
  for (int i = 0; i < n; ++i) 
    cin >> field[i];
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int cntq = 0, cntf = 0;
  for (int j = 0; j < m; ++j){
    for (int i = 0; i < n; ++i){
      if (field[i][j] == '.' || visited[i][j]) continue;
      int cnt = 0;
      for (; cnt < 5 && field[i + cnt][j] == '#' && !visited[i + cnt][j]; ++cnt);

      if (cnt == 3){
        // q;
        ++cntq;
        
        visited[i][j] = true;
        visited[i + 1][j] = true;
        visited[i + 2][j] = true;
        
        visited[i][j + 1] = true;
        visited[i + 2][j + 1] = true;
        
        visited[i][j + 2] = true;
        visited[i + 1][j + 2] = true;
        visited[i + 2][j + 2] = true;
        visited[i + 3][j + 2] = true;
        visited[i + 4][j + 2] = true;
      }
      else{
        //f;
        ++cntf;

        visited[i][j] = true;
        visited[i + 1][j] = true;
        visited[i + 2][j] = true;
        visited[i + 3][j] = true;
        visited[i + 4][j] = true;

        visited[i][j + 1] = true;
        visited[i + 2][j + 1] = true;

        visited[i][j + 2] = true;
      }
    }
  }
  cout << cntq << ' ' << cntf << '\n';
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
        solveL();
    }
}


/*
*/