def find_left_part(s):
    ln = 0
    for c in s:
        if c=="0":
            return ln
        ln += 1
    return ln

def find_right_part(s):
    ln =0
    for i in range(len(s)-1, -1, -1):
        if s[i]=="0":
            return ln
        ln += 1
    return ln

def find_middle_part(s, l_s, r_s):
    return s[l_s:len(s)-r_s]

def is_real_middle(s, g):
    if (len(g)==0 and len(s)>0):
        return False
    i = 0
    j = 0
    s_ones_count = 0
    g_ones_count = 0
    while (i<len(s) and j<len(g)):
        if g[j] == "0":
            if s[i] == "0":
                i+=1
                j+=1
                continue
            else:
                i+=1
                continue

        while (j<len(g) and g[j]=="1"):
            g_ones_count += 1
            j += 1
        for k in range(g_ones_count):
            if (i==len(s)):
                break
            if s[i]=="1":
                s_ones_count += 1
            i+=1
        while (i<len(s) and s_ones_count < g_ones_count):
            if s[i]=="1":
                s_ones_count +=1
            if s[i-g_ones_count] == "1":
                s_ones_count -=1
            i+=1

        if s_ones_count <g_ones_count:
            return False
        else:
            s_ones_count = 0
            g_ones_count = 0

    if j < len(g):
        return False
    return True
        
def main(s, g):
    l_s = find_left_part(s)
    l_g = find_left_part(g)
    if l_s < l_g:
        print("no")
        return "no"
    
    r_s = find_right_part(s)
    r_g = find_right_part(g)
    if r_s < r_g:
        print("no")
        return "no"

    m_s = find_middle_part(s, l_s, r_s)
    m_g = find_middle_part(g, l_g, r_g)
    if not is_real_middle(m_s, m_g):
        print("no")
        return "no"
    print("yes")
    return "yes"

def perebor(s, need):
    if (s == need):
        return True
    if (len(s) <= len(need)):
        return False
    ans = False
    for i in range(len(s) - 1):
        new_el = "0"
        if (s[i] == s[i + 1] and s[i] == '1'):
            new_el = "1"
        new_s = s[:i] + new_el + s[i + 2:]
        ans = ans | perebor(new_s, need)
    return ans

def stupid(s1, s2):
    ans = perebor(s1, s2)
    if (ans):
        return 'yes'
    else:
        return 'no'

def test():
    for x in range(256):
        print(x)
        for y in range(256):
            s = bin(x)[2:]
            g = bin(y)[2:]
            ans_pred = main(s, g)
            ans_true = stupid(s, g)
            if ans_pred != ans_true:
                print(s, g)
                print(ans_pred, ans_true)
                assert 2+2 ==3

tt = int(input())

for t in range(tt):
    n, m = map(int, input().split())
    s = input()
    g = input()
    main(s, g)