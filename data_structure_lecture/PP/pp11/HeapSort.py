
def reheap_down(elements, root, bottom):
    left = 2*root + 1
    right = 2*root + 2
    if left <= bottom:

        if left == bottom:
            max_node = left
        else:
            if elements[left] <= elements[right]:
                max_node = right
            else:
                max_node = left
        if elements[root] < elements[max_node]:
            elements[root], elements[max_node] = elements[max_node], elements[root]
            reheap_down(elements, max_node, bottom)

def heap_sort(values, num_values):
    
    for idx in range(num_values//2-1, -1, -1):
        reheap_down(values, idx, num_values-1)

    for i in range(num_values-1, 0, -1):
        values[0], values[i] = values[i], values[0]
        reheap_down(values, 0, i-1)