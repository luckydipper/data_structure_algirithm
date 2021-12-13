def insertion_sort(values):
    for sorted_boundary_index, _ in enumerate(values):
        for searching_index in range(sorted_boundary_index+1):
            if values[searching_index] >= values[sorted_boundary_index]:
                temp = values[sorted_boundary_index]
                del values[sorted_boundary_index]
                values.insert(searching_index, temp)
            