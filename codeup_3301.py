#minimum 거스름 돈

#50000 10000 1000 500 100 10

should_give = int(input())
result_num = 0

while should_give != 0:
    if should_give // 50000 > 0:
        result_num = result_num + should_give // 50000
        should_give %= 50000

    elif should_give //10000 > 0:
        result_num = result_num + should_give // 10000
        should_give %= 10000

    elif should_give // 5000 > 0:
        result_num = result_num + should_give // 5000
        should_give %= 5000

    elif should_give // 1000 > 0:
        result_num = result_num + should_give // 1000
        should_give %= 1000

    elif should_give // 500 > 0:
        result_num = result_num + should_give // 500
        should_give %= 500
    
    elif should_give // 100 > 0:
        result_num = result_num + should_give // 100
        should_give %= 100

    elif should_give // 50 > 0:
        result_num = result_num + should_give // 50
        should_give %= 50

    elif should_give // 10 > 0:
        result_num = result_num + should_give // 10
        should_give %= 10

print(result_num, end="")