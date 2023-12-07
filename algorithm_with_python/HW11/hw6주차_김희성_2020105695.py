

class Node:
    def __init__(self,data):
        self.data = data
        self.r_child = None  
        self.l_child = None  


class BST:
    def __init__(self):
        self.root = None

    def isLeafNode(self, ptr:Node):
        if(ptr.l_child == ptr.r_child == None):
            return True
        else:
            return False
        
    def insert(self, data:int):
        if self.root is None:
            self.root = Node(data)
        else:
            parent_node = self.root
            child_node = self.root
            while( child_node is not None):
                if(child_node.data < data):
                    parent_node = child_node
                    child_node = child_node.r_child
                else:
                    parent_node = child_node
                    child_node = child_node.l_child
            
            if(parent_node.data < data):
                parent_node.r_child = Node(data)
            else:
                parent_node.l_child = Node(data)

    def impPrintPreOrder(self, node:Node):
        if(node == None):
            return
        print(node.data)
        self.impPrintPreOrder(node.l_child)
        self.impPrintPreOrder(node.r_child)
       
    def printPreOrder(self):
        self.impPrintPreOrder(self.root)
        


    def delete(self, data:int):
        return

#p1. BST 구현


def problem1():
    nodes = [9, 8, 12, 4, 2, 6, 11, 13, 1, 3, 5, 7, 10, 14]
    bst = BST()

    for node in nodes:
        bst.insert(node)
    bst.printPreOrder()
    return 


def linearInterpolationSearch(arr:[int], first:int, last:int, seek:int):
    if(first > last):
        return
    seeking_index = first + int(  (seek-arr[first])*(last-first) /(arr[last]-arr[first])  )
    if arr[seeking_index] is seek:
        return seeking_index

    if arr[seeking_index] < seek:
        return linearInterpolationSearch(arr, seeking_index+1, last, seek)
    else:
        return linearInterpolationSearch(arr, first, seeking_index-1, seek)


def robustLinearInterpolationSearch(arr:[int], first:int, last:int, seek:int):
    import math
    if(first > last):
        return
    gap = int(math.sqrt(last - first +1))

    seeking_index = first + int(  (seek-arr[first])/(arr[last]-arr[first])*(last-first)   )
    seeking_index = min(last - gap, max(seeking_index, first + gap))
    if arr[seeking_index] is seek:
        return seeking_index

    if arr[seeking_index] < seek:
        return linearInterpolationSearch(arr, seeking_index+1, last, seek)
    else:
        return linearInterpolationSearch(arr, first, seeking_index-1, seek)
    
def problem2():
    S = [1,3,4,7,8,11,13,15,16,20,22,25,29,30,33,36,37,39,41,43,45,48]
    x = 11
    print(S)

    print(f'Location of {x:d} is {linearInterpolationSearch(S,0,len(S)-1,x)}th')
    print(f'Location of {x:d} is {robustLinearInterpolationSearch(S,0,len(S)-1,x)}th')
    import time
    import random

    S = list(range(10000))
    x = random.choice(S)
    S.append(100000)


    start = time.time()
    print(f'Location of {x:d} is {linearInterpolationSearch(S,0,len(S)-1,x)}:dth. Process time is {round(time.time()-start, 6)}')


    start = time.time()
    print(f'Location of {x:d} is {robustLinearInterpolationSearch(S,0,len(S)-1,x):d}th. Process time is {round(time.time()-start, 6)}')



    return 


def main():
    problem1()
    problem2()

    return

if(__name__ == "__main__"):
  
    main()
