# Competitive Programming

My solutions to competitive programming problems — mostly
[Codeforces](https://codeforces.com) — together with a small library of reusable
algorithm and data-structure templates. Primarily C++, with some Python.

## Repository layout

| Path | Contents |
|------|----------|
| `old_submissions/` | Archive of accepted solutions, organized by contest id (C++ and Python). |
| `algo/` | Reusable algorithm & data-structure implementations (see below). |
| `new_contest.sh` | Scaffolds a whole contest folder from the Codeforces API. |
| `new_problem.sh` | Scaffolds a single problem file from the template. |

Solutions span 250+ contests. New problems are drafted in a local, git-ignored
`contests/` workspace; finished solutions live in `old_submissions/`.

## `algo/` — templates

Data structures and algorithms kept ready to drop into a solution:

- **Data structures:** DSU, Segment Tree, Segment Tree with lazy propagation,
  Sparse Table, Trie, hash map / string hashing.
- **Graphs:** Dijkstra, LCA.
- **Strings:** prefix function, Z-function, hashing.
- **Number theory / math:** sieve of Eratosthenes, binary exponentiation,
  Euler's totient (φ).
- **Misc:** competitive template, stopwatch.

## Scaffolding

```bash
./new_contest.sh <contestId>            # whole contest -> contests/<id>/A.cpp, B.cpp, …
./new_problem.sh <contestId> <index>    # single problem -> contests/<id>/<index>.cpp
```

`new_contest.sh` fetches the contest's problem list from the Codeforces API;
`new_problem.sh` works offline. Neither overwrites an existing file. Both write
into the local `contests/` workspace, which is not tracked by git.

## Building a solution

```bash
g++ -std=c++23 -O2 file.cpp -o sol && ./sol < input.txt
```
