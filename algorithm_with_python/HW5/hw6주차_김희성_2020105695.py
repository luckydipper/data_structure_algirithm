
class Node:
    def __init__(self,data):
        self.l_child=None
        self.r_child=None
        self.data = data

def tree(key:[str], r:[[int]], i:int, j:int)->Node:
    k=r[i][j]
    if(k==0):
        return
    else:
        p=Node(key[k])
        p.l_child=tree(key,r,i,k-1)
        p.r_child=tree(key,r,k+1,j)
        return p
    
def print_2d_matrix(a:[[int]]):
    for i in a:
        for j in i:
            print(j, end=" ")
        print()
    return

def print_inorder(root:Node):
    if(root == None):
        return
    print_inorder(root.l_child)
    print(root.data)
    print_inorder(root.r_child)

def print_preorder(root:Node):
    if(root == None):
        return
    print(root.data)
    print_inorder(root.l_child)
    print_inorder(root.r_child)


# n개의 key가 있을 때, 각 key를 찾을 확률이 존재할 때, 최적의 bst를 구하시오.
# 1~n까지의 원소가 있을 때, k번째 키가 루트가 되는 경우, 트리의 평군 검색 시간
# A[1][n] = min{1~k~n}(A[1][K-1] + A[k+1][n]) + sigma_{1~n} p
# A[i][i] = p_i

# c_i : bst에서 현재 보고 있는 key_i를 찾기 위한 비교 횟수 
# p_i : 현재 보고 있는 노드 key_i가 검색키일 확률 
# A[i][j] = i부터 j까지 key를 포함 하는 최적의 bst에서 element를 찾는 평균 비교 횟수  
# r[i][j] => 
def problem_1():
    key=[" ","A","B","C","D","E"]
    p=[0, 4/16, 3/16, 6/16, 2/16, 1/16 ]#p1=4/16, p2=3/16, p3=6/16, p4=2/16, p5=1/16 
    n=len(p)-1
    a=[[0 for j in range(0,n+2)] for i in range(0,n+2)]
    r=[[0 for j in range(0,n+2)] for i in range(0,n+2)]
    for i in range (1,n+1):
        a[i][i-1]=0
        a[i][i]=p[i]
        r[i][i]=i
        r[i][i-1]=0
        a[n+1][n]=0
        r[n+1][n]=0
    print()
    for diagonal in range(1,n):
        for first in range(1, n-diagonal+1):
            last = first + diagonal
            a[first][last] = 2147483647 # INFINITY
            for k in range(first, last):
                if( a[first][last] > a[first][k-1] + a[k+1][last]):
                    a[first][last] = a[first][k-1] + a[k+1][last]
                    r[first][last] = k
            sum_p = 0
            for elem_p in p[first:last]:
                sum_p += elem_p 
            a[first][last] += sum_p

    root=tree(key,r,1,n)
    
    print_2d_matrix(a)
    print()
    print_2d_matrix(r)
    print()
    print_inorder(root)
    print()
    print_preorder(root)
    return


# p[i][j] = i~N까지 j~M까지 array를 활용하여 만들 수 있는 최적 맞춤 비용.
#                                      j에 gap을 넣음. i에 gap을 넣음. i j 가 맞아 떨어지거나, 틀린 것을 감수함
# p[i][j] =  if(arr[i] != arr[j]): min(2+ p[i+1][j], 2+p[i][j+1], 1+p[i+1][j+1]// else  p[i]
def max_DNA_cost(i: int, j:int, arr1:[int], arr2:[int], cache:[[int]], path:[[(int,int)]])->int:
    if(i == len(arr1)):
        cache[i][j] = 2*(len(arr2) - j )
        return cache[i][j]
    elif(j == len(arr2)):
        cache[i][j] = 2*(len(arr1) - i )
        return cache[i][j]

    if(cache[i][j] != 0):
        return cache[i][j]

    panalty = 1
    if(arr1[i] == arr2[j]):
        panalty = 0
    
    cache[i][j] = 2147483647 #INF
    if(cache[i][j] > max_DNA_cost(i+1,j,arr1,arr2,cache,path)+2):
        cache[i][j] = max_DNA_cost(i+1,j,arr1,arr2,cache,path)+2
        path[i][j] = i+1, j
    if(cache[i][j] > max_DNA_cost(i,j+1,arr1,arr2,cache,path)+2):
        cache[i][j] = max_DNA_cost(i,j+1,arr1,arr2,cache,path)+2
        path[i][j] = i, j+1
    if(cache[i][j] > max_DNA_cost(i+1,j+1,arr1,arr2,cache,path)+panalty):
        cache[i][j] = max_DNA_cost(i+1,j+1,arr1,arr2,cache,path)+panalty
        path[i][j] = i+1, j+1
    
    return cache[i][j]

# p[i][j] = i~N까지 j~M까지 array를 활용하여 만들 수 있는 최적 맞춤 비용
def problem_2():
    a=['C','A','G','A','C','T','A','A']
    b=['C','C','G','C','T','A','C']
    m=len(a)
    n=len(b)
    table=[[0 for j in range(0,n+1)] for i in range(0,m+1)]
    minindex = [[ (0,0) for j in range(0,n+1)] for i in range(0,m+1)]
    
    for j in range(n-1,-1,-1):
        table[m][j] =table[m][j+1]+2
    for i in range(m-1,-1,-1):
        table[i][n] =table[i+1][n]+2

    max_DNA_cost(0,0,a,b,table,minindex)

    print_2d_matrix(table)
    x=0
    y=0
    while (x <m and y <n):
        tx, ty = x, y
        print(minindex[x][y])
        (x,y)= minindex[x][y]
        if x == tx + 1 and y == ty+1:
            print(a[tx]," ", b[ty])
        elif x == tx and y == ty+1:
            print(" - ", " ", b[ty])
        else:
            print(a[tx], " " , " -")
    return


def main():
    print("---problem 1 solution---")
    problem_1()

    print("---problem 2 solution---")
    problem_2()
    return

count_compare = 0
if(__name__ == "__main__"):
  
    main()
