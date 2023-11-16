# 현재 코드 : vertex_index에 setting color를 넣을 때 promissing 한 지 체크하는 코드 
# 추천 코드 : v_color만 보고 promissing한지 판단 하기 -> 이 조건을 base case에 넣어서 출력
def has_indipendent_color(vertex_idx:int, setting_color:int, adj_mat:[[int]], v_colors:[int]):
    for adj_vertex, is_connected in enumerate(adj_mat[vertex_idx]):
            if(is_connected):
                if(setting_color == v_colors[adj_vertex]):
                    return False
    return True

# 이 코드는 매우 비효율적임. 끝날 때 마다 O(N)한번씩 더돌아야함. 완전탐색 * N 임.
def m_coloring(starting_vertex: int, v_color:[int], adj_mat:[[int]]):
    if(starting_vertex == len(v_color)):
        for color in v_color:
            if color == 0:
                return
        print(v_color)
        return
    
    num_node = len(adj_mat)

    for i in range(starting_vertex, num_node):
        for color in range(1,4): # m = 3 : color 갯수
            if(has_indipendent_color(i, color, adj_mat, v_color)):
                v_color[i] = color
                m_coloring(starting_vertex+1, v_color, adj_mat)
                v_color[i] = 0

def problem_2():
    n=4
    W=[[0,1,1,1],[1,0,1,0],[1,1,0,1],[1,0,1,0]]
    vcolor=n*[0] 
    m_coloring(0, vcolor, W)    
    return

# backtracking 보다는 vector의 subset을 추출하는 것 활요임.
# subset들의 sum을 확인 하는 과정에서, sorted된 것을 이용하여 prunning 하는 것으로 보면 됨. 
# starting index 이후의 원소들의 합하여, target-weight를 만드는 경우의 수를 출력.
def sum_of_subset(starting_index:int, total:int, target_weight:int, sorted_weights:[int], is_visited:[int]):
    if(starting_index == len(sorted_weights)):
        return
    
    for i in range(starting_index, len(sorted_weights)):
        if(total + sorted_weights[i] <= target_weight):
            is_visited[i] = 1
            if(total + sorted_weights[i] == target_weight):
                print(is_visited)
            sum_of_subset(i+1, total+sorted_weights[i],target_weight,sorted_weights, is_visited)
            is_visited[i] = 0
        else: 
            return # prunning 과정. 이후에는 더 큰 weight만 있으니 안 해도 됨. 


def problem_1():
    n=4
    w=[1,2,4,6]
    W=6
    print("items =",w, "W =", W)
    include = n*[0]
    total=0

    for k in w:
        total+=k

    sum_of_subset(0,0, W, w, include)

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
