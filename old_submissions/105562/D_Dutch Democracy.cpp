#include <chrono>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using v_pll = vector<pll>;

bool cmp(const std::string& lhs, const std::string& rhs){
    std::string lhs_cmp;
    std::string rhs_cmp;
    for (int i=0; i<lhs.size(); i++){
        if (lhs.at(i)>='A' && lhs.at(i)<='Z'){
            lhs_cmp = lhs.substr(i, lhs.size());
            break;
        }
    }
    for (int i=0; i<rhs.size(); i++){
        if (rhs.at(i)>='A' && rhs.at(i)<='Z'){
            rhs_cmp = rhs.substr(i, rhs.size());
            break;
        }
    }
    return lhs_cmp<rhs_cmp;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> cnt(n);
    for (int i=0; i<n; i++){
        cin >> cnt[i];
    }
    sort(cnt.rbegin(), cnt.rend());
    ll s = 0;
    for (auto x: cnt){
        s+=x;
    }
    vector<vector<ll>> dp(s+1, vector<ll>(n, 0));
    vector<ll> dp_pref_sum(s+1, 0);
    for (int i=0; i<n; i++){
        auto new_dp_pref_sum = dp_pref_sum;
        ll curr_val = cnt.at(i);
        dp[curr_val][i] = 1;
        new_dp_pref_sum[curr_val] += 1;
        for (int j=0; j<=s; j++){
            if (j+curr_val>s){
                continue;
            }
            dp[j+curr_val][i] += dp_pref_sum.at(j);
            new_dp_pref_sum[j+curr_val] += dp_pref_sum.at(j);
            // cerr << dp[5][0] << " " << i << " " << j << "\n";
        }
        dp_pref_sum = new_dp_pref_sum;
    }
    ll pol = (s+2)/2;
    ll ans = 0;
    for (int i = 0; i<n; i++){
        for (int j=0; j<=s; j++){
            // cerr << dp[j][i] << ' ';
            ll curr_val = cnt.at(i);
            if (j-curr_val<pol && j>=pol){
                ans += dp[j][i];
            }
        }
        // cerr << '\n';
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t =1;
    //cin >> t;
    while(t--){
        solve();
    }
}