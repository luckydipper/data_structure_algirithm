def split(values, first, last):
    pivot = values[first]
    first_index = first
    first += 1
    while True:
        while first <= last:
            if values[first] > pivot:
                break
            else:
                first += 1

        while first <= last:
            if values[last] <= pivot:
                break
            else:
                last -= 1    

        if first < last:
            values[first], values[last] = values[last], values[first]
            first += 1
            last -= 1

        if first > last:
            break
        
    split_index = last
    values[first_index], values[split_index] = values[split_index], values[first_index]
    return split_index
    
def quick_sort(values, first, last):
    if first < last:
        splitPoint = split(values, first, last)
        quick_sort(values, first, splitPoint-1)
        quick_sort(values, splitPoint+1, last)        
