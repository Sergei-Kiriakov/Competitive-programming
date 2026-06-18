#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

namespace {

using ll = long long;
using namespace std;

ll exclude_min(multiset<ll>& videos){
  auto it = videos.begin();
  auto val = *it;
  videos.erase(it);
  // cerr << val << " ";
  return val;
}

ll exclude_max(multiset<ll>& videos){
  auto it = videos.end();
  it--;
  auto val = *it;
  videos.erase(it);
  // cerr << val << " ";
  return val;
}

ll exclude_low_bound(multiset<ll>& videos, ll limit){
  if (*videos.begin() > limit){
    return exclude_max(videos);
  }

  auto it = videos.lower_bound(limit);
  if (it == videos.end() || *it > limit){
    it--;
  }

  auto val = *it;
  videos.erase(it);
  // cerr << val << " ";
  return val;
}

void solve(){
  ll n,k;
  cin >> n >> k;
  multiset<ll> videos;
  for (int i=0; i<n; i++){
    ll x;
    cin >> x;
    videos.insert(x);
  }

  ll ans = 0;
  while (!videos.empty()){
    auto s = exclude_min(videos);
    if (videos.empty()){
      break;
    }
    if (s >= k){
      ans++;
      continue;
    }

    s += exclude_low_bound(videos, k-s-1);
    if (videos.empty()){
      break;
    }
    if (s >= k){
      ans++;
      continue;
    }

    s += exclude_max(videos);
    if (videos.empty()){
      break;
    }
    ans++;
  }

  cout << ans << '\n';
}

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t --> 0){
    solve();
  }
}

//  g++ -std=c++20 1.cpp -o a.out && ./a.out
