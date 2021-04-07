import copy


#이항 계수 계산하기 (Combination nCk)

def binominal_coefficient(n, k):
    '''
    (int, int) -> int
    @params : n combination k
    '''

    # Index가 0부터 시작하므로 n+1 table 생성
    ans_table = [[0] * (n+1) for _ in range(n+1)]

    #0부터 n까지 수행
    for i in range(n+1):
        for j in range(min(i+1,k+1)): # 코드 수행의 효율성을 올리기 (필요 없는 연산은 제외)

            if j == 0 or j == i:
                ans_table[i][j] = 1
            else:
                ans_table[i][j] = ans_table[i-1][j-1] + ans_table[i-1][j]

    return ans_table[n][k]

print(binominal_coefficient(4,2))


