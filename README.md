# Competitive Programming

My solutions to competitive programming problems — mostly
[Codeforces](https://codeforces.com) — together with a small library of reusable
algorithm and data-structure templates. Primarily C++, with some Python.

## Repository layout

| Path | Contents |
|------|----------|
| `contests/` | Per-contest working files, one source file per problem (`<id>/<letter>.cpp`). |
| `old_submissions/` | Archive of accepted solutions, organized by contest id (C++ and Python). |
| `algo/` | Reusable algorithm & data-structure implementations (see below). |
| `new_contest.sh` | Helper that scaffolds a contest folder from the Codeforces API. |

Solutions span 250+ contests.

## `algo/` — templates

Data structures and algorithms kept ready to drop into a solution:

- **Data structures:** DSU, Segment Tree, Segment Tree with lazy propagation,
  Sparse Table, Trie, hash map / string hashing.
- **Graphs:** Dijkstra, LCA.
- **Strings:** prefix function, Z-function, hashing.
- **Number theory / math:** sieve of Eratosthenes, binary exponentiation,
  Euler's totient (φ).
- **Misc:** competitive template, stopwatch.

## Scaffolding a new contest

```bash
./new_contest.sh <contestId>        # e.g. ./new_contest.sh 2031
```

Fetches the contest's problem list from the Codeforces API and creates
`contests/<contestId>/A.cpp`, `B.cpp`, … from a template. Existing files are
never overwritten.

## Building a solution

```bash
g++ -std=c++17 -O2 "contests/<id>/<letter>.cpp" -o sol && ./sol < input.txt
```
