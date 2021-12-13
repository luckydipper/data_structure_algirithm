
def selection_sort(values):
    for sorted_boundery_index, _  in enumerate(values):
        smallest_index = sorted_boundery_index
        
        # searching smallest index
        for searching_index in range(sorted_boundery_index, len(values)):
            if values[smallest_index] > values[searching_index]:
                smallest_index = searching_index
    
        # switch sorted_boundery_index to smallest index
        temp = values[sorted_boundery_index]
        values[sorted_boundery_index] = values[smallest_index]
        values[smallest_index] = temp
            

    
