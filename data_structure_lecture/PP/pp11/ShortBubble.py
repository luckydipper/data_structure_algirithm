
def short_bubble(values, num_values):
    current = 0
    sorted = False
    while(current < num_values - 1 and not sorted):
        sorted = bubble_up(values, current, num_values-1, sorted)
        current += 1

def bubble_up(values, start_index, end_index, sort):
    sorted = True
    for i in range(end_index, start_index, -1):
        if values[i] < values[i-1]:
            values[i], values[i-1] = values[i-1], values[i]
            sorted = False
    return sorted        
