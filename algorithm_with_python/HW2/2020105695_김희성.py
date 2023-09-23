import random 
from time import time
merge1_cache = {}
marge2_additional_space = []
def memory_trace(func):
    def wrapper(*args, **kwargs):
        rt = func(*args, **kwargs)
        print(f'{func.__name__}\'s additional memory is a list containing {rt} elements.')
        return rt
    return wrapper


def merge1(arr: [int], tmp:[int],  l: int, m: int, r: int):
    pl = l
    pr = m

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

    return 

def merge2(arr: [int], l: int, m: int, r: int):
    pl = l
    pr = m
    

    for i in range(0, r-l):
        if pl == m:
            marge2_additional_space[i] = arr[pr]
            pr += 1
        elif pr == r:
            marge2_additional_space[i] = arr[pl]
            pl += 1
        elif(arr[pl] > arr[pr]):
            marge2_additional_space[i] = arr[pr]
            pr += 1
        else:
            marge2_additional_space[i] = arr[pl]
            pl += 1

    for i,arr_idx in enumerate(range(l, r)):
        arr[arr_idx] = marge2_additional_space[i]

    return 


def merge_sort1_implement(arr: [int], begin: int, end: int) -> int:
    if(begin+1 >= end):
        return arr
    
    mid = int( (begin+end)/2 )
    merge_sort1_implement(arr, begin, mid)
    merge_sort1_implement(arr, mid, end)

    # 전역 변수 할당
    if merge1_cache.get(end-begin) == None:
        merge1_cache[end-begin] = [0 for i in range(end-begin)]

    tmp = merge1_cache[end-begin] 
    merge1(arr, tmp, begin, mid, end)
    additional_memory_size = sum(merge1_cache.keys())
    return additional_memory_size 


def merge_sort2_implement(arr: [int], begin: int, end: int) -> int:
    if(begin+1 >= end):
        return arr
    
    mid = int( (begin+end)/2 )
    merge_sort2_implement(arr, begin, mid)
    merge_sort2_implement(arr, mid, end)

    # 처음 부터 메모리를 빌리고 시작.
    global marge2_additional_space
    marge2_additional_space = [0 for _ in range(len(arr))]
    merge2(arr, begin, mid, end)
    additional_memory_size = len(marge2_additional_space)
    # 메모리 할당 해제
    del marge2_additional_space
    return additional_memory_size # slice array를 보내면, 이 부분에서 call by value 가 됨. 

@memory_trace
def merge_sort_1(arr:[int]) -> int:
    return merge_sort1_implement(arr, 0, len(arr))

@memory_trace
def merge_sort_2(arr: [int]) -> int:
    return merge_sort2_implement(arr, 0, len(arr))


def main():
    arr = [3,9,10,1, 2,16,13,8, 7,4,12,6, 5,11,14,15]
    # merge_sort2_implement 함수 안에서 전역 변수 할당하고 해제 함. 
    merge_sort_2(arr)
    for i in arr:
        print(i,end=", ")

    print()
    arr = [3,9,10,1, 2,16,13,8, 7,4,12,6, 5,11,14,15]

    # 시작하기 전에 3행에 merge1_cache = {}로 받아놨음. 함수에서 추가 해서 쓸 것임.
    global merge1_cache
    merge_sort_1(arr)
    del merge1_cache
    for i in arr:
        print(i,end=", ")



if(__name__ == "__main__"):
    main()
