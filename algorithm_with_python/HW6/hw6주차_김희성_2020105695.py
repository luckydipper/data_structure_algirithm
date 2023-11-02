from queue import PriorityQueue


def dijkstra(num_edge:int, adj_list:[[int]], F, is_determined:[bool], length:[int], start_idx:int) -> None:
    pq = PriorityQueue()
    pq.put((0, start_idx, start_idx)) #weight start arrive

    while(not pq.empty()):
        min_weight_here, start, arrive = pq.get()
        
        # check visit
        length[arrive] = min(min_weight_here, length[arrive])
        is_determined[arrive] = True
        F.add((start, arrive))

        for there in range(num_edge):
            if(is_determined[there]):
                continue
            else:
                pq.put( (min_weight_here + adj_list[arrive][there], arrive, there) ) 

    return


def problem_1():
    inf=1000
    w=[ 
        [0,7,4,6,1],
        [inf,0,inf,inf,inf],
        [inf,2,0,5,inf], 
        [inf,3,inf,0,inf], 
        [inf,inf,inf,1,0]
    ]


    # v_near는 length에서 최단 경로로 가는 vetex의 index로 가기 위한 것이므로 
    # priority queue 쓰면 안 써도 됨.
    n=5
    f=set() # 이게 무슨 의미가 있는지 모르겠음. 그냥 is visited 대신 쓰라는 것인지..
    touch=n*[0] # 
    length=n*[inf] # shortest path from 0 index vertex
    save_length=n*[0]
    is_ditermined = [False for _ in range(n)]
    dijkstra(n,w,f,is_ditermined, length, start_idx=0 )

    print(length)
    return 



def main():
    print("---problem 1 solution---")
    problem_1()
    return

count_compare = 0
if(__name__ == "__main__"):
  
    main()
