def merge_sort(values, first, last):
    if(first < last):
        middle = (first + last)//2
        merge_sort(values, first, middle)
        merge_sort(values, middle+1, last)
        merge(values, first, middle, middle+1, last)


def merge(values, leftFirst, leftLast, rightFirst, rightLast):
    starting_index = leftFirst
    temp = []
    
    while(leftFirst <= leftLast and rightFirst <= rightLast):
        if values[leftFirst] < values[rightFirst]:
            temp.append(values[leftFirst])
            leftFirst += 1
        else:
            temp.append(values[rightFirst])
            rightFirst += 1
            
    while(leftFirst <= leftLast):
        temp.append(values[leftFirst])
        leftFirst += 1
        
    while(rightFirst <= rightLast):
        temp.append(values[rightFirst])
        rightFirst += 1
        
    for i, elem in enumerate(temp):
        sort_boundery_index = starting_index + i
        values[sort_boundery_index] = elem
    
