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
    vector<string> a(n);
    getline(cin, a[0]);
    for (int i=0; i<n; i++){
        getline(cin, a[i]);
    }
    std::sort(a.begin(), a.end(), cmp);
    for (const auto& s: a){
        cout << s << '\n';
    }
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