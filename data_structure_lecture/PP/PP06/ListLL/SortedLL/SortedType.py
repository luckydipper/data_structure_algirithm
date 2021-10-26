from typing import Iterator


class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class SortedType:
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

    def retrieve_item(self, item):
        location = self.listData
        found = False
        moreToSearch = location != None

        while moreToSearch and not found:
            if location.info < item:
                location = location.next
                moreToSearch = location != None
            elif location.info == item:
                found = True
            else:
                moreToSearch = False

        return found

    def insert_item(self, item):
        location = self.listData
        predLoc = None
        moreToSearch = location != None
        inserted_node = NodeType(item)

        if (self.length == 0):
            self.listData = inserted_node
        elif(inserted_node.info < self.listData.info):
            inserted_node.next = self.listData
            self.listData = inserted_node
        elif(True):
            while(location != None):
                # 
                if(location.info > inserted_node.info):
                    inserted_node.next = location
                    predLoc.next = inserted_node
                    self.length += 1
                    return
                predLoc = location
                location = location.next
            # item is largest
            predLoc.next = inserted_node
        
        
        self.length += 1


    def delete_item(self, item):

        if(self.length == 0):
            return
                
        iterator = self.listData

        if(iterator.info == item):
            self.length -= 1
            del self.listData

        while(iterator.next != None):
            if(iterator.next.info == item):
                self.length -= 1
                iterator.next = iterator.next.next
            iterator = iterator.next
   
        
        
        
        
    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        item = self.currentPos.info
        self.currentPos = self.currentPos.next

        return item

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            t = self.get_next_item()
            items.append(str(t))
        return " ".join(items)
