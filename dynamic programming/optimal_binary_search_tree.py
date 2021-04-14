import utility

class Node:
    def __init__(self,data):
        self.l_child = None
        self.r_child = None
        self.data = data

def tree(val, root_table, start, end):
    root_node = root_table[start][end]
    if root_node == 0:
        return
    else:
        present_node = Node(val[root_node])
        present_node.l_child = tree(val, root_table, start, root_node - 1)
        present_node.r_child = tree(val, root_table, root_node + 1, end)
        return present_node




''' ----- main ----- '''

key=["A","B","C","D","E"]
p=[4/15,5/15, 1/15, 3/15,2/15]
n=len(p)-1

a=[[0 for j in range(0,n+2)] for i in range(0,n+2)] # 최소의 비교 횟수 값 정렬 table
r=[[0 for j in range(0,n+2)] for i in range(0,n+2)] # root node info table

for i in range (1,n+1):
    a[i-1][i]=0 # diagonal
    a[i][i]=p[i]

    r[i-1][i]=0 #diagonal
    r[i][i]=i

#a[n+1][n]=0
#r[n+1][n]=0


for diag in range(1,n):
    for i in range(1, n-diag+1):
        j = i + diag
        minimum_val = 10000000
        prob = 0

        # comparison value
        for k in range(i, j+1):
            compare = a[i][k-1] + a[k+1][j]
            if minimum_val > compare:
                minimum_val = compare
                minimun_k = k

        r[i][j] = minimun_k

        # calculate probability
        prob = p[i]
        for idx in range(i+1, j + 1):
            prob = prob + p[idx]

        a[i][j] = minimum_val + minimun_k

minavg = a[1][n]


utility.printMatrix_float(a)
print()
utility.printMatrix_int(r)

root= tree(key, r, 1, n)

utility.print_inOrder(root)
print()
utility.print_preOrder(root)



# DNA

print("\n DNA algoritms\n")

a=['A','A','C','A','G','T','A','C','C']

b=['T','A','C','G','T','T','C','A']

m=len(a)
n=len(b)
table=[[0 for j in range(0,n+1)] for i in range(0,m+1)] # m+1 x n+1 table

minindex = [[ (0,0) for j in range(0,n+1)] for i in range(0,m+1)]
# 왜 튜플로 넣었지?


# 마지막 행 / 열 값 넣기
for j in range(n-1,-1,-1):
    table[m][j] =table[m][j+1]+2

for i in range(m-1,-1,-1):
    table[i][n] = table[i+1][n]+2

# 최적서열맞춤 테이블 완성

for j in range(1, m):
    # traversing downwards starting
    # from last column
    col = n - 1
    row = j
    while (row < n):
        # 1. penalty 계산
        if table[row] == table[col]:
            penalty = 0
        else:
            penalty = 1

        # 2. opt 계산
        optimum = min(table[row+1][col+1] + penalty, table[row+1][col] + 2, table[row][col+1] + 2)
        table[row][col] = optimum
        row += 1
        col -= 1


utility.printMatrix(table)

x=0
y=0

#while (x <m and y <n):
tx, ty = x, y
print(minindex[x][y])
(x,y)= minindex[x][y]
if x == tx + 1 and y == ty+1:
    print(a[tx]," ",  b[ty])
elif x == tx and y == ty+1:
    print(" - ", " ", b[ty])
else:
    print(a[tx], " " , " -")
