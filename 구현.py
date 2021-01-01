import collections# count deque
#itertool permutation product combination combination_with_replacement
#heaps heap 자료구조
#bisect 이진탐색
# math gcd lcm
#sum min max eval

#programus code up 백준에서 풀어보기

#탐욕(greedy) : 매 순간 최선
#구현(사뮬레이션) : 풀이는 쉬운데 코드가 어려움
#ex) 방향벡터 2차원 좌표평면. 움직임을 표현하는 것 부터
#완전탐색: 다 해보는 것. 계산 속도를 이용해
# 
#. 
arr1 = ['l','l',"r","r","r",'r']

def udlr(arr):
    count_r = 0
    count_l = 0
    count_u = 0
    count_d = 0
    result_x = 0
    result_y = 0
    for element in arr1:
        if element == 'r' and count_l < count_r:
            result_x += 1
            count_r += 1
        elif element == 'r' and count_l >= count_r:
            count_r += 1

        elif element == 'l' and count_l < count_r:
            result_x -= 1
            count_l += 1
        elif element == 'l' and count_l >= count_r:
            count_l += 1

        elif element == 'u' and count_u < count_d:
            result_y -= 1
            count_u += 1
        elif element == 'u' and count_u >= count_d:
            count_u += 1
            
        elif element == 'd' and count_u < count_d:
            result_y += 1
            countd += 1
        elif element == 'd' and count_u >= count_d:
            countd += 1
        else:
            print('오류')
    return  result_x, result_y


print(collections.Counter("hello world"))
print(udlr(arr1))