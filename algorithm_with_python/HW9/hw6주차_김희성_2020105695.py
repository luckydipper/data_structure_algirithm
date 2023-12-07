import queue
class Node:
    def __init__(self, level, profit, bound, weight):
        self.level = level
        self.profit = profit
        self.bound = bound
        self.weight = weight


def bound(u:Node):
    global weight_threshold, profits, weights, current_max_profit, is_included, maxProfit,bestset
    if u.weight >= weight_threshold:
        return 0

    profitBound = u.profit
    j = u.level + 1
    totWeight = int(u.weight)
 
    while j < n and totWeight + weights[j]<= weight_threshold:
        totWeight += weights[j]
        profitBound += profits[j]
        j += 1

    if j < n:
        profitBound += int((weight_threshold - totWeight) * profits[j] / weights[j])
 
    return profitBound
 

def knapsack_BFS(n):
    global weight_threshold, profits, weights, current_max_profit, is_included, maxProfit,bestset
    q = queue.PriorityQueue()
    u = Node(-1, 0, 0, 0)

    q.put( (u.bound, u))

    maxProfit = 0
 
    while not q.empty():
        b ,u = q.get()
 
        if u.level == -1:
            v = Node(0, 0, 0, 0)
 
        if u.level == n - 1:
            continue

        v = Node(u.level + 1, u.profit +
                 profits[u.level + 1], 0, u.weight + weights[u.level + 1])

        if v.weight <= weight_threshold and v.profit > maxProfit:
            maxProfit = v.profit

        v.bound = bound(v)
 
        if v.bound > maxProfit:
            q.put((v.bound, v))
 
        v = Node(u.level + 1, u.profit, 0, u.weight)
 
        v.bound = bound(v)
 
        if v.bound > maxProfit:
            q.put((v.bound, v))
    

    return maxProfit

def problem_2():
    global n, weight_threshold, profits, weights, current_max_profit, is_included, maxProfit,bestset
    n=4
    weight_threshold=16
    profits=[40,30,50,10]
    weights=[2,5,10,5]
    is_included=[0]*n
    maxProfit =0
    knapsack_BFS(n )
    print(-1*maxProfit)
    print(bestset)

    return



# bound : 현 상태에서 얻을 수 있는 최대 이익
# i부터 끝까지의 원소를 사용하여, 만들 수 있는 최적의 원소를 include에 저장..
# here의 next 원소부터 profit의 값이 최고가 되는 is_include값을 찾음.
def knapsack(here, profit, weight):
    global n, weight_threshold, profits, weights, current_max_profit, is_included, bestset

    next = here + 1
    if(next == n):
        if(profit > current_max_profit):
            current_max_profit = profit
            bestset = is_included.copy()
        return 0
    
    # next is pickable
    if(weight + weights[next] <= weight_threshold):
        is_included[next] = 1
        knapsack(next, profit+profits[next],weight+weights[next])

        is_included[next] = 0
        knapsack(next, profit, weight)
    else:
        knapsack(next, profit, weight)
    # next is not picked.


# bestset을 그 순간의 include 값을 저장한다. 이후 include 일부 값이 변해도
# bestset의 값은 바뀌지 않음.

def problem_1():
    global n, weight_threshold, profits, weights, current_max_profit, is_included, bestset
    n=4
    weight_threshold=16
    profits=[40,30,50,10]
    weights=[2,5,10,5]
    current_max_profit=0
    is_included =[0,0,0,0]
    bestset = [0,0,0,0]
    knapsack(-1,0,0)
    print(current_max_profit)
    print(bestset)
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
