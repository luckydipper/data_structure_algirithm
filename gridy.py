# 2초, 128mb 
# 큰것 부터 그러니깐 현재 상황에서 가장 적합 한 것 부터 가장 큰 것부터 고르는 방법
def until1(n, k):
    #return (n // 4) + (n % 4)
    result = 0
    while n != 1:
        if n % k == 0:
            result += 1
            n /= k
        else:
            result += 1
            n -= 1
    return result


def mul_plus():
    number = input()
    result = int(number[0])
    for k in range(1,len(number)):
        if result <=1 or int(number[k]) <= 1:
            result += int(number[k])
        else:
            result *= int(number[k])
    return result


