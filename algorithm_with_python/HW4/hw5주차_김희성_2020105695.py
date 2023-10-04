import math

INF = 2147483647
weighted_graph = [
        [],
        [INF,   0,   4, INF, INF, 4  ],
        [INF,   6,   0, INF, INF, INF],
        [INF,   1,   2,   0,   1, INF],
        [INF, INF, INF,   4,   0, INF],
        [INF,   9, INF,   3,   5, 0  ],
]

def allShortestPath(weighted_graph:[[int]], num_node:int):
    path = [[0 for i in range(num_node+2)] for j in range(num_node+2)]
    distance = weighted_graph.copy()

    for i in range(1,num_node+1):
        path[i][i] = i
        for j in range(1,num_node+1):
            if(weighted_graph[i][j]!=INF):
                path[i][j] = j
            
    for through in range(1, num_node+1):
        for start in range(1, num_node+1):
            for arrive in range(1, num_node+1):
                if(weighted_graph[start][arrive] > weighted_graph[start][through] + weighted_graph[through][arrive]):
                    path[start][arrive] = through
                distance[start][arrive] = min(distance[start][arrive], distance[start][through] + distance[through][arrive])

    return distance, path

def print_path(path:[[int]], start:int, arrive:int):
    if(path[start][arrive] == arrive):
        return
    through = path[start][arrive]
    print_path(path, start, through)
    print_path(path, through, arrive)
    print(through, end=" -> ")


def problem_1():
    
    distance, path = allShortestPath(weighted_graph, len(weighted_graph)-1)

    start, arrive = 2, 4
    print(f"distance from {start} to {arrive} is {distance[start][arrive]}")
    print(start, "-> ",end="")
    print_path(path, start, arrive)
    print(arrive)
    return

# d= matrix info, n = num_matrix임. 너무 알아보기 힘들어서 이름하고 index+-1만 바꿈.
matrix_ =[5,2,3,4,6,7,8]
num_matrix = len(matrix_)

m=[[INF for j in range(num_matrix+1)] for i in range(num_matrix+1)]
p=[[0 for j in range(num_matrix+1)] for i in range(num_matrix+1)]

# 그냥 recursion으로 풀음..
def matrix_chain_multiple(first: int, last: int,cache:[[int]] ):
    if(first == last):
        cache[first][last] = 0
        return 0
    
    if (cache[first][last] != INF):
        return cache[first][last]
    
    for k in range(first, last+1):
        devided = matrix_chain_multiple(first,k,cache) + matrix_chain_multiple(k+1,last,cache) + matrix_[first-1] * matrix_[k] * matrix_[last]
        if(cache[first][last] > devided):
            cache[first][last] = devided
            p[first][last] = k
        
    return cache[first][last]

    

def order(p,i,j):
    if(i == j):
        print(i, end="")
        return
    print("(",end="")
    # print(p[i][j], i, j, end="")
    order(p,i,p[i][j])
    order(p,p[i][j]+1,j)
    print(")",end="")



def problem_2():
    first, last = 1, 5
    print(f"Matrix rows and columns information is {matrix_}")
    print(f"Matrix from {first} to {last}, the minimum number of operation is {matrix_chain_multiple(first, last, m)}")
    print(f"And the shortest sequence is ")
    order(p, first, last)
    return 


def main():
    problem_1()
    problem_2()
    return

count_compare = 0
if(__name__ == "__main__"):
  
    main()
