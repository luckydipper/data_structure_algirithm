
def split(values, first_index, last_index):
    split_value = values[first_index]
    initial_index = first_index
    first_index +=1
    while(first_index <= last_index):
        #맨 앞의 값을 기준으로 자기보다 크거나 같은 것 잡음
        while(first_index <= last_index and values[first_index] <= split_value):
            first_index += 1

        #맨 뒤를 기준으로 자기보다 작은 것을 집음
        while(first_index <= last_index and values[last_index] > split_value):
            last_index -= 1


        # pivot을 기준으로 큰 것과 작은 것을 바꿈.
        if (first_index < last_index):
            temp = values[first_index]
            values[first_index] = values[last_index]
            values[last_index] = temp
            first_index += 1
            last_index -= 1
    
    temp = values[initial_index]
    values[initial_index] = values[last_index]
    values[last_index] = temp
    return last_index
        

def quick_sort(values, first, last):
    if(first < last):
        splitpoint = split(values,first,last)
        quick_sort(values,first,splitpoint-1)
        quick_sort(values,splitpoint+1,last)
    return values

