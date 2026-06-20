#!/usr/bin/env bash
# Создаёт папку контеста и по одному .cpp на каждую задачу с твоим шаблоном.
# Использование:  ./new_contest.sh <contestId>
# Пример:         ./new_contest.sh 2031   ->  ./contests/2031/A.cpp, ./contests/2031/B.cpp, ...
# Уже существующие файлы не перезаписываются.

BASE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
UA="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 Chrome/124.0 Safari/537.36"

cid="$1"
if [ -z "$cid" ]; then
    echo "Использование: $0 <contestId>"
    exit 1
fi

# Список задач контеста через Codeforces API
# ВАЖНО: для обычных контестов API требует запрос только с contestId, без extra-параметров
json="$(curl -s -A "$UA" "https://codeforces.com/api/contest.standings?contestId=$cid")"

if ! printf '%s' "$json" | grep -q '"status":"OK"'; then
    echo "Не удалось получить контест $cid. Ответ API:"
    printf '%s\n' "$json" | head -c 300
    echo
    exit 1
fi

# Индексы задач: A, B, C1, ...
indices="$(printf '%s' "$json" | grep -oE '"index":"[^"]+"' | sed -E 's/.*"index":"([^"]+)".*/\1/')"

if [ -z "$indices" ]; then
    echo "В контесте $cid не найдено задач."
    exit 1
fi

dir="$BASE_DIR/contests/$cid"
mkdir -p "$dir"

created=""
skipped=""
for idx in $indices; do
    f="$dir/$idx.cpp"
    if [ -e "$f" ]; then
        skipped="$skipped $idx.cpp"
        continue
    fi
    cat > "$f" <<'EOF'
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

using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

int solve (int n, vector<int> a) {
    int ans = 0;

    return ans;
}

void input() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ans = solve(n, a);
    cout << ans << endl;
}

int32_t main()
{
    int tt = 1;
    cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
EOF
    created="$created $idx.cpp"
done

echo "Контест $cid -> $dir"
[ -n "$created" ] && echo "Создано:  $created"
[ -n "$skipped" ] && echo "Пропущено (уже есть): $skipped"
