import copy


#최단경로 알고리즘 (Floyd) - 최단경로 테이블만 반환

def allShortestPath(graph):
    '''
    (list, int) -> list, path
    @params : graph : 노드 간 arc(간선)의 정보를 담은 행렬
    return  : 모든 노드간 weight 합 matrix
    big-O : n^3
    '''

    shortest_path_table = copy.deepcopy(graph)
    node_num = len(graph[0])
    # 1번 노드부터 마지막 노드까지 수행하며 테이블을 업데이트
    for k in range(node_num): # 각각 거치는 노드 기준으로 수행
        for i in range(node_num):
            for j in range(node_num):
                # min (바로 가는 방법 , k노드를 거쳐 가는 방법)
                shortest_path_table[i][j] = min(shortest_path_table[i][j], shortest_path_table[i][k] + shortest_path_table[k][j])

    return shortest_path_table


#최단경로 알고리즘2 (Floyd) - 최단경로 테이블과 최단 경로 인덱스 테이블을 모두 반환

def allShortestPath2(graph):
    '''
    (list, int) -> list, list
    @params : graph : 노드 간 arc(간선)의 정보를 담은 행렬
              node_num : 노드의 개수
     return : 최단경로 weight 합 테이블 , 최단경로 인덱스 테이블
    '''

    node_num = len(graph[0])
    # 최단경로 table
    shortest_path_table = copy.deepcopy(graph)
    # 0으로 초기화한 path table
    path_index_table = [[0] * node_num for _ in range(node_num)]


    # 1번 노드부터 마지막 노드까지 수행하며 테이블을 업데이트
    for k in range(node_num): # 각각 거치는 노드 기준으로 수행
        for i in range(node_num):
            for j in range(node_num):
                if (shortest_path_table[i][k] + shortest_path_table[k][j]) < shortest_path_table[i][j]:
                    path_index_table[i][j] = k+1 #가장 큰 index update
                    shortest_path_table[i][j] = shortest_path_table[i][k] + shortest_path_table[k][j] #최단경로 weight 업데이트

    return shortest_path_table, path_index_table



def printPath(path_index_table, _from, _to):
    '''
    (list, int, int) -> void
    desc    : print shortest path nodes from node i to node j
    @param  : i : from node index, j : to node index, path_index_table : table that contains path index information
    @return : void
    '''
    # index adjustment
    i = _from - 1
    j = _to - 1

    if path_index_table[i][j] != 0:
        printPath(path_index_table, i+1, path_index_table[i][j])
        print("v"+ str(path_index_table[i][j]), end= " ")
        printPath(path_index_table, path_index_table[i][j], j+1)

''' ## test case ## '''

i = int(1000) # infinite value

graph = [[0, 1, i, 1, 5],
         [9, 0, 3, 2, i],
         [i, i, 0, 4, i],
         [i, i, 2, 0, 3],
         [3, i, i, i, 0]]

d1 = allShortestPath(graph)

d2, p2 = allShortestPath2(graph)

print("initial matrix : \n")
printMatrix(graph)

print("Floyd1 알고리즘 결과 : \n")
printMatrix(d1)

print("Floyd2 알고리즘 결과 : \n\n- 최단경로 weight table - ")
printMatrix(d2)
print("- 최단경로 index table -")
printMatrix(p2)

print("3. 최단경로 노드 출력 ")

# utility function
def printMatrix(matrix):
    length = len(matrix[0])
    for i in range(0,length):
        for j in range(0,length):
            print(str(matrix[i][j]), end = " ")
        print('\n')
