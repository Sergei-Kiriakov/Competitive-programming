n, m, r = map(int, input().split())

submission_strings = []
rank_by_id = dict()
id_by_rank = dict()
q = 0
for i in range(n):
    rank_by_id[i] = i
    id_by_rank[i] = i
    subm_string = input()
    submission_strings.append(list(subm_string))
    q += subm_string.count('P')

for _ in range(q):
    # print(submission_strings)
    break_flag = False
    # print(_)
    for i in range(n-1, -1, -1):
        if break_flag:
            break
        for j in range(m):
            if break_flag:
                break
            if (submission_strings[i][j]!='P'):
                continue

            res = input()[10:]
            if res == 'Aaawww...':
                submission_strings[i][j] = 'R'
            submission_strings[i][j] = 'A'
            rank_up = res.count('y') - 3
            # print(i, j, rank_up)

            for k in range(rank_up):
                curr_rank, low_rank = i - k, i - k -1
                curr_id = id_by_rank[curr_rank]
                low_id = id_by_rank[low_rank]
                submission_strings[curr_rank], submission_strings[low_rank] = submission_strings[low_rank], submission_strings[curr_rank]
                id_by_rank[low_rank] = curr_id
                id_by_rank[curr_rank] = low_id
                rank_by_id[low_id] = curr_rank
                rank_by_id[curr_id] = low_rank

            break_flag = True

print(rank_by_id[r-1] + 1)