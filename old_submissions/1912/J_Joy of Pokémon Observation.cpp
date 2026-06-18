#include <chrono>
#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using v_pll = vector<pll>;

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll solve_for_one_number(ll t){
    ll n;
    cin >> n;
    if (t%n==0){
        return 1;
    }
    return 0;
}

ll solve_for_two_numbers(ll t, ll a, ll b){
    ll lcm_ab = lcm(a, b);
    ll mn = -1;
    for (ll x = 0; x*a < 2*lcm_ab && x*a <= t; x++){
        if ((t-a*x)%b==0){
            mn = (t-a*x)%lcm_ab + a*x;
            break;
        }
    }
    if (mn == -1){
        return 0;
    }
    //cerr << mn << '\n';
    ll k = (t - mn)/lcm_ab;
    return k+1;
}

ll f(ll k, ll val, ll inc){
    if (val==0){
        return 0;
    }
    return (val+inc*k + val + inc)*k/2;
}

ll solve_for_three_numbers(ll t){
    ll a, b, c;
    cin >> a >> b >> c;
    ll lcm_ab = lcm(a, b);
    ll lcm_abc = lcm(lcm_ab, c);
    vector<ll> ans_by_rem(lcm_abc*2, 0);
    for (ll rem = t%c; rem < lcm_abc*2 && rem <= t; rem += c){
        ans_by_rem[rem] = solve_for_two_numbers(rem, a, b);
    }
    ll ans = 0;
    for (auto v: ans_by_rem){
        // cerr << v << ' ';
        ans+= v;
    }
    // cerr << '\n';
    for (ll rem = lcm_abc; rem < lcm_abc*2; rem++){
        ll k = max(0ll, (t-rem)/lcm_abc);
        ll val = ans_by_rem[rem];
        ll inc = lcm_abc/lcm_ab;
        ans += f(k, val, inc);
    }
    return ans;
}

void solve(){
    ll t, s;
    cin >> t >> s;
    if (s==1){
        cout << solve_for_one_number(t);
    } else if (s==2){
        ll a, b;
        cin >> a >> b;
        cout << solve_for_two_numbers(t, a, b);
    } else {
        cout << solve_for_three_numbers(t);
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t =1;
    cin >> t;
    while(t--){
        solve();
    }
}