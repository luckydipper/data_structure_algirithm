#minimum click time?
#1
#5
#10

start_end = input()
defuault_aim = start_end.split()
default = int(defuault_aim[0]) # 0 이라고 가정해 풀어보자.
aim = int(defuault_aim[1])

result = 0

offset = abs(aim - default)

if offset % 10 == 0:
    result = offset // 10
elif offset % 10 == 1:
    result = offset // 10 + 1
elif offset % 10 == 2:
    result = offset // 10 + 2
elif offset % 10 == 3:
    result = offset // 10 + 3
elif offset % 10 == 4:
    result = offset // 10 + 2
elif offset % 5 == 0:
    result = offset // 10 + 1
elif offset % 10 == 6:
    result = offset // 10 + 2
elif offset % 10 == 7:
    result = offset // 10 + 3
elif offset % 10 == 8:
    result = offset // 10 + 3
elif offset % 10 == 9:
    result = offset // 10 + 2

print(result, end="")