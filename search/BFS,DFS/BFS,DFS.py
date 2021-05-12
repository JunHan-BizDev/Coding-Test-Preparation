import queue

# 1. set up the graph
e={0:[1,2,3], 1:[2,5], 2:[3,4,5,6], 3:[4,6],4:[6,7]}
n=8
a = [ [0 for j in range(0,n)] for i in range(0,n)]
for i in range(0,n-1):
    for j in range(i+1,n):
        if i in e:
           if j in e[i]:
              a[i][j]=1
              a[j][i]=1

visited =n*[0]


''' DFS(Depth First Search)'''
# 방문했을때 수행
def action(node):

    print(node)

def DFS(matrix, start):
    action(start) # action
    visited[start] = 1 # Check the visited node

    for idx in range(len(matrix[start])):
        if (visited[idx] != 1) & (matrix[start][idx] == 1):
            DFS(matrix, idx)


''' BFS(Breadth First Search)'''
q=queue.Queue()
def BFS(matrix, start):
    node = -1 # initialize node
    action(start) # action
    visited[start] = 1 # Check the visited node

    # enqueue all nodes
    for idx, elem in enumerate(matrix[start]):
        if elem == 1:
            q.put(idx)

    #visit
    while not q.empty():
        node = q.get()
        if visited[node] != 1:
            BFS(matrix, node)






''' ---- utility functions  ----'''

def printMatrix(d):
    m = len(d)
    n = len(d[0])

    for i in range(0, m):
        for j in range(0, n):
            print("%4d" % d[i][j], end=" ")
        print()


# print float matrix
def printMatrixF(d):
    n = len(d[0])
    for i in range(0, n):
        for j in range(0, n):
            print("%5.2f" % d[i][j], end=" ")
        print()


def print_inOrder(root):
    if not root:
        return
    print_inOrder(root.l_child)
    print(root.data)
    print_inOrder(root.r_child)


def print_preOrder(root):
    if not root:
        return
    print(root.data)
    print_preOrder(root.l_child)
    print_preOrder(root.r_child)

def print_postOrder(root):
    if not root:
        return

    print_postOrder(root.l_child)
    print_postOrder(root.r_child)
    print(root.data)
