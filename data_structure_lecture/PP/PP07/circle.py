from typing import Iterator


class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class CircularLL:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def is_full(self):
        try:
            location = NodeType("test")
            return False
        except:
            return True

    def length_is(self):
        return self.length

    def make_empty(self):
        while self.listData != None:
            tempPtr = self.listData.next
            del self.listData
            self.listData = tempPtr
        self.length = 0

    #find가 return 하는 iterator의 뒤에 inseted 돼야함.
    def find_item(self, listData, item):
        # 굳이 listData를 받아야만 했나?
        iterator = listData
        while(iterator != listData):
            if(iterator.next.info >= item):
                return iterator
            iterator = iterator.next
        return iterator
    
    def insert_item(self, item):
        '''[5]'''
        new_node = NodeType(item)
        if(self.length == 0):
            new_node.next = new_node
            self.listData = new_node
        else:
            location = self.find_item(self.listData, item)
            new_node.next = location.next
            location.next = new_node
            # listdata 뒤에 붙을 경우.
            if(self.listData.info < new_node.info):
                self.listData = new_node
        self.length += 1
        


    def delete_item(self, item):
        iterator = self.listData
        for _ in range(self.length+1):
            if(iterator.next.info == item):
                iterator.next = iterator.next.next
                self.length -= 1
            iterator = iterator.next

    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        else:
            self.currentPos = self.currentPos.next
        return self.currentPos.info

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            t = self.get_next_item()
            items.append(str(t))
        return " ".join(items)
