import random
import math
#global count_compare

def partition(arr:[int], begin:int, end:int) -> int:
    global count_compare
    l_ptr, r_ptr = begin+1, end-1
    pivot = begin
    while(True):

        while(arr[l_ptr] <= arr[pivot] and l_ptr < end): # arr[pivot]보다 큰 element 찾아.
            count_compare += 1
            l_ptr += 1
        while(arr[r_ptr] >= arr[pivot] and r_ptr > pivot): # arr[pivot]보다 작은 elem 찾깁
            count_compare += 1
            r_ptr -= 1
        
        # if l_ptr == r_ptr == pivot +1: r_ptr 이 pivot까지 갈 수 있도록 하여서 
        #     if(arr[pivot] > arr[l_ptr]):
        #         arr[r_ptr], arr[pivot] = arr[pivot], arr[r_ptr] 
        #     return pivot
        # if l_ptr == r_ptr == end -1: end 에 inf 원소를 넣어서 l_ptr이 end까지 닿을 수 있도록
        #     count_compare += 1
        #     arr[r_ptr], arr[pivot] = arr[pivot], arr[r_ptr]
        #     return r_ptr    

        if(l_ptr > r_ptr): # equal인 경우는 없음. 무조건 cross 되게 되어 있음.
            arr[r_ptr], arr[pivot] = arr[pivot], arr[r_ptr]
            return r_ptr    
        arr[l_ptr], arr[r_ptr] = arr[r_ptr], arr[l_ptr]



def quickSort(arr:[int], begin:int, end:int):
    if end - begin <= 1:
        return 
    pivot_indx = partition(arr, begin, end)

    quickSort(arr, begin, pivot_indx)
    quickSort(arr, pivot_indx+1, end)
    
def solveP1():
    global count_compare
    random.seed(14)
    n = [100, 200, 300, 400]
    for n_ in n:
        count_compare = 0
        for _ in range(100):
            random_arr = [random.randrange(n_+1) for _ in range(n_)]
            # array의 끝에 padding을 붙혀서 일관성 있게 코딩 하려고 함.
            random_arr.append(math.inf)
            quickSort(random_arr,0, len(random_arr)-1)
            random_arr.pop()
        print(f"When n = {n_}, Avereage compare number is {count_compare/100}")


def solveMul(a:int, b:int):
    threshold = 2
    digit_number = max(len(str(a)), len(str(b)))
    if(digit_number <= threshold):
        return a * b
    else:
        digit_center = 10** int(digit_number/2)
        x, y = int(a /digit_center), a%digit_center
        w, z = int(b /digit_center), b%digit_center
        r = solveMul(x+y,w+z)
        p = solveMul(x,w)
        q = solveMul(y,z)
        return p*digit_center*digit_center+ (r-p-q)*digit_center + q

def solveP2():
    # test data
    a=1234567812345678
    b=2345678923456789
    result = solveMul(a,b)
    print(f"{a} * {b} = {result}")
    return result
    

def main():
    print("(1) solution")
    solveP1()
    print("(2) solution")
    solveP2()



    

count_compare = 0
if(__name__ == "__main__"):
  
    main()
