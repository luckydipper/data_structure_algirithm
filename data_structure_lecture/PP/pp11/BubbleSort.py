
def bubble_sort(values):
    
    for sorted_boundery_index, _  in enumerate(values):
        smallest_index = len(values) -1
        
        for reverse_index in range(len(values) -1, sorted_boundery_index ,-1):
            if(values[reverse_index-1] > values[reverse_index]):
                temp = values[reverse_index-1]
                values[reverse_index-1] = values[reverse_index]
                values[reverse_index] = temp



