from SortedType import *

if __name__ == '__main__':
    student_list = SortedType()
    
    student_list.insert_item("이준범", 2014104132) 
    student_list.insert_item("임연수", 2020310153) 
    student_list.insert_item("이준범", 2020310152) 
    student_list.insert_item("김봉민", 2017103969) 
    student_list.insert_item("임연수", 2014104139) 
    student_list.insert_item("김봉민", 2021311013) 
    
    print(student_list)