
arr = []
strr = input()
arr.append(strr)
if strr != "end":
    while strr != "end":
        strr = input()
        if strr != "end":
            arr.append(strr)

# print(arr)

for i in arr:
    flag = 0
    # 1번 규칙 : 모음을 반드시 한개는 포함해라
    if "a" not in i and "e" not in i and "i" not in i and "o" not in i and "u" not in i:
        flag = 1
        # print("f : ", flag)

    # 2번 규칙 : 자음 혹은 모음이 연달아 세번 나오면 안된다.
    # 3번 규칙 : 같은 글자가 연속적으로 오면 안된다. 다만 ee, oo는 가능
    s_list = list(i)
    tmp = s_list[0]
    for idx, j in enumerate(s_list):
        if len(i) >= 2:
            if idx < len(i) - 1 and j == s_list[idx + 1]:
                if j != "e" and j != "o":
                    flag = 1

        if idx < len(i) - 2 and len(i) >= 3:
            if j == "a" or j == "e" or j == "i" or j == "o" or j == "u":
                if s_list[idx + 1] in ["a", "e", "i", "o", "u"]:
                    if s_list[idx + 2] in ["a", "e", "i", "o", "u"]:
                        flag = 1
            else:
                if s_list[idx + 1] not in ["a", "e", "i", "o", "u"]:
                    if s_list[idx + 2] not in ["a", "e", "i", "o", "u"]:
                        flag = 1

    if flag == 1:
        s = "<" + i + "> is not acceptable."
        print(s)
    elif flag == 0:
        s = "<" + i + "> is acceptable."
        print(s)
