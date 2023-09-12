
import random 
from time import time

def time_trace(func):
    def wrapper(*args, **kwargs):
        st = time()
        rt = func(*args, **kwargs)
        print(f'{func.__name__} execution time : {time()-st:.3f}ms')
        return rt
    return wrapper

@time_trace
def selection_sort(arr : [int]) -> [int]:
    size = len(arr)
    for i in range(size):
        max_index = i
        for j in range(i+1, size):
            if arr[max_index] > arr[j]:
                max_index = j
        arr[i], arr[max_index] = arr[max_index], arr[i] # swap
    return arr



def merge(arr: [int], l: int, m: int, r: int) -> [int]:
    pl = l
    pr = m
    tmp = [0 for _ in range(r-l)]

    for i in range(0, r-l):
        if pl == m:
            tmp[i] = arr[pr]
            pr += 1
        elif pr == r:
            tmp[i] = arr[pl]
            pl += 1
        elif(arr[pl] > arr[pr]):
            tmp[i] = arr[pr]
            pr += 1
        else:
            tmp[i] = arr[pl]
            pl += 1

    for i,arr_idx in enumerate(range(l, r)):
        arr[arr_idx] = tmp[i]

    return arr

def merge_sort_implement(arr: [int], begin: int, end: int) -> [int]:
    if(begin+1 >= end):
        return arr
    
    mid = int( (begin+end)/2 )
    merge_sort_implement(arr, begin, mid)
    merge_sort_implement(arr, mid, end)

    return merge(arr, begin, mid, end) # slice array를 보내면, 이 부분에서 call by value 가 됨. 

@time_trace
def merge_sort(arr: [int]) -> [int]:
    return merge_sort_implement(arr, 0, len(arr))



def main():
    random.seed(33)

    n = 5000
    print(f"in n = {n}")
    random_arr = [random.randrange(1,1001) for _ in range(n)]
    selection_sort(random_arr)
    random_arr = [random.randrange(1,1001) for _ in range(n)]
    merge_sort(random_arr)

    n = 10000
    print(f"in n = {n}")
    random_arr = [random.randrange(1,1001) for _ in range(n)]
    selection_sort(random_arr)
    random_arr = [random.randrange(1,1001) for _ in range(n)]
    merge_sort(random_arr)


if(__name__ == "__main__"):
    main()
