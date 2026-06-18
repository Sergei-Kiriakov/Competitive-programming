#include <chrono>
#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using v_pll = vector<pll>;

void solve(){
    ll x, k;
    cin >> x >> k;
    priority_queue<pll, v_pll, std::greater<pll>> queue;
    vector<v_pll> stacks;
    for (int i=0; i<k; i++){
        ll m;
        cin >> m;
        ll weight = 0, min_val = 0;
        v_pll rev_stack;
        for (int j=0; j<m; j++){
            ll val;
            cin >> val;
            if (val<0 && weight>0){
                rev_stack.emplace_back(-min_val, weight);
                min_val = 0;
                weight = 0;
            }
            weight += val;
            min_val = min(min_val, weight);
        }
        if (weight>0){
            rev_stack.emplace_back(-min_val, weight);
        }
        std::reverse(rev_stack.begin(), rev_stack.end());
        stacks.push_back(rev_stack);
        if (!rev_stack.empty()){
            const auto [min_val, _] = rev_stack.back();
            queue.emplace(min_val, i);
        }
    }
    while (!queue.empty() && queue.top().first<=x){
        const auto [min_val, index] = queue.top();
        auto& stack = stacks.at(index);
        const auto [_, weight] = stack.back();
        x += weight;
        stack.pop_back();
        queue.pop();
        if (!stack.empty()){
            const auto [min_val, _] = stack.back();
            queue.emplace(min_val, index);
        }
    }
    cout << x << '\n';
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