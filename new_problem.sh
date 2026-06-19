#!/usr/bin/env bash
# Создаёт одну конкретную задачу <index> в папке контеста с твоим шаблоном.
# Использование:  ./new_problem.sh <contestId> <index>
# Пример:         ./new_problem.sh 2031 C   ->  ./contests/2031/C.cpp
# Уже существующий файл не перезаписывается.

BASE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cid="$1"
idx="$2"
if [ -z "$cid" ] || [ -z "$idx" ]; then
    echo "Использование: $0 <contestId> <index>"
    echo "Пример:        $0 2031 C"
    exit 1
fi

dir="$BASE_DIR/contests/$cid"
mkdir -p "$dir"
f="$dir/$idx.cpp"

if [ -e "$f" ]; then
    echo "Уже существует (не перезаписываю): contests/$cid/$idx.cpp"
    exit 0
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

const int MOD = 1e9 + 7;

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

echo "Создано: contests/$cid/$idx.cpp"
