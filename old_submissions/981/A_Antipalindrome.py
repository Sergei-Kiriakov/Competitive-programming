def is_palindrom(s):
    ans = True
    for i in range(len(s)):
        if s[i] != s[-(i + 1)]:
            ans = False
            break
    return (ans)

def mine():
    s = input()
    left = 0
    right = 0
    len_c = 0
    while left < len(s):
        right = left + len_c + 1
        while right < len(s):
            if not(is_palindrom(s[left:right + 1])):
                len_c = max(len_c, right - left + 1)
            right += 1
        left += 1
    print(len_c)
mine()