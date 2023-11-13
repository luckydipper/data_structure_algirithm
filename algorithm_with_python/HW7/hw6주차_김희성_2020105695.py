global is_occupied_row
global is_occupied_col 
global is_occupied_diagnose1 
global is_occupied_diagnose2 
global n
n = 5
is_occupied_row = [False for _ in range(n+1)]
is_occupied_col = [False for _ in range(n+1)]
is_occupied_diagnose1 = [False for _ in range(2*n)]
is_occupied_diagnose2 = [False for _ in range(2*n)]


def promising(i:int, j: int):
    if(is_occupied_row[i]):
       return False
    if(is_occupied_col[j]):
        return False
    if(is_occupied_diagnose1[i-j+4]):
        return False
    if(is_occupied_diagnose2[i+j]):
        return False
    return True

def queens(i, picked, n):
    if(i == n):
        print(picked)

    for j in range(n):
        if(promising(i, j)):
            is_occupied_row[i] = True
            is_occupied_col[j] = True
            is_occupied_diagnose1[i-j+4] = True
            is_occupied_diagnose2[i+j] = True
            picked.append(j)
            queens(i+1, picked, n)
            is_occupied_row[i] = False
            is_occupied_col[j] = False
            is_occupied_diagnose1[i-j+4] = False
            is_occupied_diagnose2[i+j] = False
            picked.pop()

    return

def problem_2():
    picked = []
    queens(0,picked, n)
    return

def DFS(adj_mat:[[int]], here:int, is_visited:[bool]):
    is_visited[here] = True
    print(here)
    for there in range(len(adj_mat)):
        if(adj_mat[here][there]):
            if(not is_visited[there]):
                DFS(adj_mat, there, is_visited)
    return

def problem_1():
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
    DFS(a,0,visited)

def main():
    print("---problem 1 solution---")
    problem_1()
    print("---problem 2 solution---")
    problem_2()
    return

count_compare = 0
if(__name__ == "__main__"):
  
    main()
