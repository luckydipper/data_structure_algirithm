import os
from UnsortedType import *

if __name__ == '__main__':
    l = UnsortedType()
    f = open('ListLL/UnsortedLL/data.txt', 'r')
    line = f.readline()
    while line:
        i = int(line)
        l.insert_item(i)
        line = f.readline()
    f.close()
    
    print("Before:")
    print(l)
    
    print("After deleting 65:")
    a = 65
    l.delete_item(a)
    print(l)
    print()
    
    a = 3
    if l.retrieve_item(a) == True:
        print(str(a) + " is in the list.")
    else:
        print(str(a) + " is not in the list.")
        
    a = 2
    if l.retrieve_item(a) == True:
        print(str(a) + " is in the list.")
    else:
        print(str(a) + " is not in the list.")
