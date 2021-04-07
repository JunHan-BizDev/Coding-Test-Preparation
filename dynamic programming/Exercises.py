'''
이것이 코테다 책 예제
# 다이나믹 프로그래밍
'''

'''
가능한 연산 - 1 빼기, (가능시) 5로, 3으로, 2로 나누기

x가 주어졌을때, 연산 4개를 적절히 사용하여 1을 만들어야 한다.
연산을 사용하는 횟수의 '최솟값'을 구하시오
'''
# 1. 1로 만들기

def makeOne(x):

    table = [0] * (30000 + 1) # 인덱스만큼 값 저장

    for i in range(2, x+1):

        #1을 빼는 경우
        table[i] = table[i-1] + 1

        #2로 나누는 경우
        if i % 2 == 0:
            table[i] = min(table[i], table[i // 2] + 1)

        #3으로 나누는 경우
        if i % 3 == 0:
            table[i] = min(table[i], table[i // 3] + 1)

        #5로 나누는 경우
        if i % 5 == 0:
            table[i] = min(table[i], table[i // 5] + 1)


    return table[x]


print(makeOne(26))
