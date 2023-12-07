# buble sort
# merge sort

def buble_sort(arr:[int]):
    #decide  i 
    for i in range(len(arr)-1, 1, -1):
        for j in range(0, i):
            if(arr[j] > arr[j+1]):
                arr[j], arr[j+1] =  arr[j+1], arr[j] 
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


def merge_sort(arr: [int]) -> [int]:
    return merge_sort_implement(arr, 0, len(arr))

def main():
    print("---problem 1 solution---")
    s = [3,5,2,9,10,14,4,8]
    print(buble_sort(s))
    
    print("---problem 2 solution---")
    s = [3,5,2,9,10,14,4,8]
    merge_sort(s)
    print(s)
    return

count_compare = 0
if(__name__ == "__main__"):
  
    main()
