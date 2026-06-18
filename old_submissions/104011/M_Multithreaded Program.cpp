#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

const int mod = 1e9 + 7, kk = 26;

int ans = 0;

struct Vertex {
    Vertex* to[kk] = {0};
    bool terminal = 0;
    int cnt = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex* v = root;
    ++v->cnt;
    for (char c : s) {
        c -= 'a';
        if (!v->to[c])
        {
          v->to[c] = new Vertex();
        }
        v = v->to[c];
        ++v->cnt;
    }
    v->terminal = true;
}

void get_ans(Vertex* v, int k)
{
  if (v->cnt <= k)
  {
    ++ans;
    return;
  }
  for (int i = 0; i < kk; ++i)
    {
      Vertex* w = v->to[i];
      if (w->cnt != 0)
      {
        get_ans(w, k);
      }
    }
}

void solve()
{
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    {
      string s;
      cin >> s;
      add_string(s);
    }
  get_ans(root, k);
  cout << ans << endl;
}

void solveH(){
  int t;
  cin >> t;
  while (t-->0){
    int n;
    cin >> n;
    for (int i = n / 2; i > 0; --i){
      if (__gcd(i, n) == 1){
        cout << i << '\n';
        break;
      }
    }
  }
}
pair<int, pair<int, int> > min(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
  if (a.first<b.first) return a;
  else{
    int x = abs(a.second.first-a.second.second);
    int y = abs(b.second.first-b.second.second);
    if (x<y) return a;
    else return b;
  }
}
void solveK(){
  int n, m;
  cin >> n >> m;
  vector <vector <pair <int, int> > > g(n);
  for (int i=0; i<m; i++){
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  vector <pair<int, pair<int, int> > > dp(n, {1000000, {0, 0}});
  vector <int> used(n, 0);
  dp[0] = {0, {-1, -1}};
  vector <int> q;
  q.push_back(0);
  for (int i=0; i<q.size(); i++){
    if (used[q[i]]) continue;
    used[q[i]]=1;
    pair <int,pair<int, int> > b = dp[q[i]];
    for (auto e: g[q[i]]){
      if (!used[e.first]){
        q.push_back(e.first);
        pair <int, pair<int, int> > y = {b.first, {min(b.second.first, e.second), max(b.second.second, e.second)}};
        pair <int, int> p = {-1, -1};
        if (b.second == p) y.second = {e.second, e.second};
        dp[e.first] = min(dp[e.first], y);
      }
    }
  }
  cout << dp[n-1].first << '\n';
  vector <int> ans;
  ans.push_back(n-1);
  while(ans.back()!=0){
    int u = ans.back();
    pair <int, pair<int, int> > x = dp[u];
    for (auto e: g[u]){
      pair <int, pair<int, int> > b = dp[e.first];
      pair <int, pair<int, int> > y = {b.first, {min(b.second.first, e.second), max(b.second.second, e.second)}};
      if (x==y){
        ans.push_back(e.first);
        break;
      }
    }
  }
  for (int i = ans.size()-1; i>=0; i--){
    cout << ans[i]+1 << " ";
  }
}

void solveM(){
  int t;
  cin >> t;
  vector<stack<pair<string, int>>> treads(t);
  int ans_size = 0;
  for (int i = 0; i < t; ++i){
    int l;    
    cin >> l;
    ans_size += l;
    for (int j = 0; j < l; ++j){
      string line;
      cin >> line;
      int eqpos = find(line.begin(), line.end(), '=') - line.begin();
      string name = line.substr(0, eqpos);
      int value = stoi(line.substr(eqpos + 1));
      // cout << name << ' ' << value << '\n';
      treads[i].emplace(name, value);
    }
  }
  
  unordered_map<string, int> result;
  
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    string name;
    int value;
    cin >> name >> value;
    result[name] = value;
  }
  vector<int> ans;
  
  unordered_set<string> setted;
  
  while (ans.size() < ans_size){
    bool ans_changed = false;
    for (int i = 0; i < t; ++i){
      if (treads[i].empty()) 
        continue;
      auto [name, value] = treads[i].top();
      if (setted.count(name)){
        ans.push_back(i);
        treads[i].pop();
        ans_changed = true;
      }
      else if (result[name] == value){
        ans.push_back(i);
        treads[i].pop();
        setted.insert(name);
        ans_changed = true;
      }
    }
    if (!ans_changed) 
      break;
  }
  if (ans.size() == ans_size){
    cout << "Yes\n";
    for (int i = ans.size() - 1; i > -1; --i) 
      cout << ans[i] + 1 << ' ';
    cout << '\n';
  }
  else 
    cout << "No\n";
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
        solveM();
    }
}


/*
*/