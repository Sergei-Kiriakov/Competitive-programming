/*
-------------------------------------------------------------------------------------------------------------------------------
░░░░░░░░░░░▄▄▀▀▀▀▀▀▀▀▄▄
░░░░░░░░▄▀▀░░░░░░░░░░░░▀▄▄
░░░░░░▄▀░░░░░░░░░░░░░░░░░░▀▄
░░░░░▌░░░░░░░░░░░░░▀▄░░░░░░░▀▀▄
░░░░▌░░░░░░░░░░░░░░░░▀▌░░░░░░░░▌
░░░▐░░░░░░░░░░░░▒░░░░░▌░░░░░░░░▐
░░░▌▐░░░░▐░░░░▐▒▒░░░░░▌░░░░░░░░░▌
░░▐░▌░░░░▌░░▐░▌▒▒▒░░░▐░░░░░▒░▌▐░▐
░░▐░▌▒░░░▌▄▄▀▀▌▌▒▒░▒░▐▀▌▀▌▄▒░▐▒▌░▌
░░░▌▌░▒░░▐▀▄▌▌▐▐▒▒▒▒▐▐▐▒▐▒▌▌░▐▒▌▄▐
░▄▀▄▐▒▒▒░▌▌▄▀▄▐░▌▌▒▐░▌▄▀▄░▐▒░▐▒▌░▀▄
▀▄▀▒▒▌▒▒▄▀░▌█▐░░▐▐▀░░░▌█▐░▀▄▐▒▌▌░░░▀
░▀▀▄▄▐▒▀▄▀░▀▄▀░░░░░░░░▀▄▀▄▀▒▌░▐
░░░░▀▐▀▄▒▀▄░░░░░░░░▐░░░░░░▀▌▐
░░░░░░▌▒▌▐▒▀░░░░░░░░░░░░░░▐▒▐
░░░░░░▐░▐▒▌░░░░▄▄▀▀▀▀▄░░░░▌▒▐
░░░░░░░▌▐▒▐▄░░░▐▒▒▒▒▒▌░░▄▀▒░▐
░░░░░░▐░░▌▐▐▀▄░░▀▄▄▄▀░▄▀▐▒░░▐
░░░░░░▌▌░▌▐░▌▒▀▄▄░░░░▄▌▐░▌▒░▐
░░░░░▐▒▐░▐▐░▌▒▒▒▒▀▀▄▀▌▐░░▌▒░▌
░░░░░▌▒▒▌▐▒▌▒▒▒▒▒▒▒▒▐▀▄▌░▐▒▒
-------------------------------------------------------------------------------------------------------
*/

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <cassert>
#include <memory>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 998244353;

struct card {
    char action;
    int v;
};

string solve (int n, int p, int h, vector<card> cards) {
    vector<int> sums, prods;
    int cnt_at = 0;
    for (int i = 0; i < n; ++i) {
        if (cards[i].action == '!') {
            ++cnt_at;
            continue;
        }
        if (cards[i].action == '*') {
            prods.push_back(cards[i].v);
            continue;
        }
        sums.push_back(cards[i].v);
    }

    int cnt_cards = cards.size();
    int all_sum = 0;
    for (auto v : sums) {
        all_sum += v;
    }
    bool skip_first_phase = false;
    int all_prod = 1;
    for (auto v : prods) {
        all_prod *= v;
        if (all_prod > 1000000000 + 9) {
            skip_first_phase = true;
        }
    }

    sort(sums.rbegin(), sums.rend());
    sort(prods.rbegin(), prods.rend());

    if (cnt_at == 0 or (all_sum + p == 0)) {
        return "*";
    }
    int cnt_turns = 0;
    if (!skip_first_phase) {
        if (all_prod == 1 and all_sum == 1) {
            int l = 0, r = 1e9 + 9;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                if (cnt_at * (p * mid + mid) < h) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cnt_turns = l * cnt_cards;
            h -= cnt_at * (p * l + l);
            p += l;
        }
        else if (all_prod == 1 and all_sum == 0) {
            int damage = p * cnt_at;
            int cnt_blocks = (h + damage - 1) / damage - 1;
            cnt_turns = cnt_blocks * cnt_cards;
            h -= damage * cnt_blocks;
        }
        else {
            int next_damage = (p + all_sum) * all_prod * cnt_at;
            int cnt_blocks = 0;
            while (next_damage < h) {
                h -= next_damage;
                ++cnt_blocks;
                p += all_sum;
                p *= all_prod;
                next_damage = (p + all_sum) * all_prod * cnt_at;
            }
            cnt_turns += cnt_cards * cnt_blocks;
        }
    }

    if (h == 0) {
        return to_string(cnt_turns);
    }
    if (p >= h) {
        return to_string(cnt_turns + 1);
    }

    int min_turns = 1e9;
    int pref_sum = 0;
    for (int i = 0; i <= sums.size(); ++i) {
        int now_p = p + pref_sum;
        if (now_p != 0) {
            for (int j = 0; j <= prods.size(); ++j) {
                int need_at = (h + now_p - 1) / now_p;
                if (need_at <= cnt_at) {
                    min_turns = min(min_turns, i + j + need_at);
                }

                if (now_p > (int) 1e9 + 9) {
                    break;
                }
                if (j < prods.size())
                    now_p *= prods[j];
            }
        }

        if (i < sums.size())
            pref_sum += sums[i];
    }

    if (min_turns == (int) 1e9) {
        return "*";
    }
    int ans = min_turns + cnt_turns;
    return to_string(ans);
}

void stress() {
    int cnt_samples = 1e6;
    int v_bord = 1e9;
    int max_n = 50;
    for (int i = 0; i < cnt_samples; ++i) {
        cout << "==================Sample==================" << endl;
        int n = rng() % max_n + 1;
        int p = rng() % v_bord;
        int h = rng() % v_bord + 1;
        vector<card> cards(n);
        for (int i = 0; i < n; ++i) {
            int action = rng() % 3;
            if (action == 0) {
                cards[i] = {'!', 1};
                continue;
            }
            int v = rng() % v_bord + 1;
            if (action == 1) {
                cards[i] = {'+', v};
                continue;
            }
            if (action == 2) {
                cards[i] = {'*', v};
                continue;
            }
        }
        auto ans = solve(n, p, h, cards);
        cout << n << " " << p << " " << h << endl;
        for (int i = 0; i < n; ++i) {
            if (cards[i].action == '!')
                cout << cards[i].action << endl;
            else
                cout << cards[i].action << " " << cards[i].v << endl;
        }
    }
}

void input()
{
    int n, p, h;
    cin >> n >> p >> h;
    vector<card> cards (n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '!') {
            cards[i] = {c, 1};
            continue;
        }
        int v;
        cin >> v;
        cards[i] = {c, v};
    }
    auto ans = solve(n, p, h, cards);
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(9);
//    cin >> tt;

    int tt = 1;
    while(tt-->0)
    {
        input();
    }
//    stress();
}

/*
2 1 1000000000
* 1
!
*/