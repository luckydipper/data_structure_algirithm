def main():
    #input과 동시에 받아야 함.
    first_pa = int(input())
    second_pa = int(input())
    third_pa = int(input())
    
    first_ju = int(input())
    second_ju = int(input())
    
    pa_list = [first_pa, second_pa, third_pa]
    ju_list = [first_ju, second_ju]
    
    min_pa = min(pa_list)
    min_ju = min(ju_list)
    
    result = (min_pa + min_ju)*1.1
    rount_result = round(result, 1)
    print(rount_result, end="")

main()